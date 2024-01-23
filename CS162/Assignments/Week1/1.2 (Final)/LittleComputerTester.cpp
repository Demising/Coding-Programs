//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;
//-----------------------------------------------------------------------------------


#include <string>
#include "LittleComputer.h"

using namespace std;

int program2[] = {108, 309, 610, 308, 209, 108, 309, 0, 12, 0, 108, 603};
int program2Length = 12;

TEST_CASE( "default constructor - memory not tested" ) {
    LittleComputer c1;
    CHECK( c1.getAccumulator() == 0 );
    CHECK( c1.getProgramCounter() == 0 );

    LittleComputer c2;
    CHECK( c2.getAccumulator() == 0 );
    CHECK( c2.getProgramCounter() == 0 );
}

TEST_CASE( "default constructor - test memory" ) {
    LittleComputer c1;
    for(int i = 0; i < 20; i++)
        CHECK( c1.getMemoryAt(i) == 0 );

    LittleComputer c2;
    for(int i = 0; i < 20; i++)
        CHECK( c2.getMemoryAt(i) == 0 );
}

    TEST_CASE( "constructor that takes program" ) {
        //Program that adds 10 to itself and prints answer
        int program[] = { 504, 104, 902, 0 , 10 };
        int programLength = 5;

        LittleComputer c1(program, programLength);

        //verify program was stored
        for(int i = 0; i < programLength; i++)
            CHECK( c1.getMemoryAt(i) == program[i] );

        //verify rest of memory is clear
        for(int i = programLength; i < 20; i++)
            CHECK( c1.getMemoryAt(i) == 0 );

        LittleComputer c2(program2, program2Length);

        for(int i = 0; i < program2Length; i++)
            CHECK( c2.getMemoryAt(i) == program2[i] );

        for(int i = program2Length; i < 20; i++)
            CHECK( c2.getMemoryAt(i) == 0 );
    }

    TEST_CASE( "getCurrentInstruction start" ) {
        //Program that adds 10 to itself and prints answer
        int program[] = { 504, 104, 902, 0 , 10 };
        int programLength = 5;

        LittleComputer c1(program, programLength);
        CHECK( c1.getCurrentInstruction() == 504 );

        LittleComputer c2(program2, program2Length);
        CHECK( c2.getCurrentInstruction() == 108 );
    }

    TEST_CASE( "step advances to next instruction" ) {
        //Program that Adds 5 to itself
        int program[] = { 502, 102, 5 };
        int programLength = 3;

        LittleComputer c1(program, programLength);
        c1.step();
        CHECK( c1.getProgramCounter() == 1 );
        CHECK( c1.getCurrentInstruction() == 102 );

        LittleComputer c2(program2, program2Length);
        c2.step();
        CHECK( c2.getProgramCounter() == 1 );
        CHECK( c2.getCurrentInstruction() == 309 );
    }

    TEST_CASE( "isHalted and step does not advance halted program" ) {
        //Program that Adds 5 to itself and halts
        int program[] = { 104, 104, 0, 104, 7 };
        int programLength = 5;

        LittleComputer c1(program, programLength);
        CHECK( c1.isHalted() == false );
        c1.step();
        CHECK( c1.isHalted() == false );
        c1.step();
        CHECK( c1.isHalted() == true );
        CHECK( c1.getProgramCounter() == 2 );
        c1.step();
        CHECK( c1.isHalted() == true );
        CHECK( c1.getProgramCounter() == 2 );

        LittleComputer c2(program2, program2Length);
        CHECK( c2.isHalted() == false );
        c2.step();
        CHECK( c2.isHalted() == false );
        c2.step();
        CHECK( c2.isHalted() == false );
        c2.step();
        CHECK( c2.isHalted() == false );
        c2.step();
        CHECK( c2.isHalted() == false );
        c2.step();
        CHECK( c2.isHalted() == false );
        c2.step();
        CHECK( c2.isHalted() == false );
        c2.step();
        CHECK( c2.isHalted() == false );
        c2.step();
        CHECK( c2.isHalted() == false );
        c2.step();
        CHECK( c2.isHalted() == true );
        CHECK( c2.getProgramCounter()  == 7);
        c2.step();
        CHECK( c2.isHalted() == true );
        CHECK( c2.getProgramCounter()  == 7);
        c2.step();
        CHECK( c2.isHalted() == true );
        CHECK( c2.getProgramCounter()  == 7);
        c2.step();
        CHECK( c2.isHalted() == true );
        CHECK( c2.getProgramCounter()  == 7);
        c2.step();
        CHECK( c2.isHalted() == true );
        CHECK( c2.getProgramCounter()  == 7);
    }

    TEST_CASE( "step add and subtract work" ) {
        //Program that adds 5 twice then subtracts 7
        int program[] = { 104, 104, 205, 0, 5, 7 };
        int programLength = 6;

        LittleComputer c1(program, programLength);
        c1.step();
        CHECK( c1.getAccumulator() == 5 );
        c1.step();
        CHECK( c1.getAccumulator() == 10 );
        c1.step();
        CHECK( c1.getAccumulator() == 3 );

        LittleComputer c2(program2, program2Length);
        c2.step();
        CHECK( c2.getAccumulator() == 12 );
        c2.step();
        c2.step();
        c2.step();
        CHECK( c2.getAccumulator() == 24 );
        c2.step();
        c2.step();
        c2.step();
        CHECK( c2.getAccumulator() == 12 );
        c2.step();
        CHECK( c2.getAccumulator() == 36 );
    }


    TEST_CASE( "step load and store work" ) {
        //Program that loads from 5, stores it to location 12,
        // loads from 6, reloads the value that was stored to 12
        int program[] = { 505, 312, 506, 512, 0, 3, 8 };
        int programLength = 7;

        LittleComputer c1(program, programLength);
        c1.step();
        CHECK( c1.getAccumulator() == 3 );
        c1.step();
        CHECK( c1.getAccumulator() == 3 );
        CHECK( c1.getMemoryAt(12) == 3 );
        c1.step();
        CHECK( c1.getAccumulator() == 8 );
        c1.step();
        CHECK( c1.getAccumulator() == 3 );

        LittleComputer c2(program2, program2Length);
        c2.step();
        c2.step();
        CHECK( c2.getMemoryAt(9) == 12 );
        c2.step();
        c2.step();
        c2.step();
        c2.step();
        CHECK( c2.getMemoryAt(8) == 24 );
        c2.step();
        c2.step();
        c2.step();
        CHECK( c2.getMemoryAt(9) == 36 );
    }

    TEST_CASE( "branch always" ) {
        //Program that jumps to instruction 3 then 1
        int program[] = { 603, 0, 0, 601, 0 };
        int programLength = 5;

        LittleComputer c1(program, programLength);
        c1.step();
        CHECK( c1.getProgramCounter() == 3 );
        c1.step();
        CHECK( c1.getProgramCounter() == 1 );

        LittleComputer c2(program2, program2Length);
        c2.step();
        c2.step();
        c2.step();
        CHECK( c2.getProgramCounter() == 10 );
        c2.step();
        c2.step();
        CHECK( c2.getProgramCounter() == 3 );
    }

    TEST_CASE( "branch if 0" ) {
        //Program that skips instruction 1 due to branch
        //Then loads 5 and hits anohter branch. Does not take it.
        int program[] = { 702, 0, 505, 701, 0, 5 };
        int programLength = 6;

        LittleComputer c1(program, programLength);
        c1.step();
        CHECK( c1.getProgramCounter() == 2 );
        c1.step();
        c1.step();
        CHECK( c1.getProgramCounter() == 4 );
    }

    TEST_CASE( "restart" ) {
        //Program that Adds 5 to itself and halts
        int program[] = { 103, 103, 0, 5 };
        int programLength = 4;

        LittleComputer c1(program, programLength);
        c1.step();
        c1.step();
        CHECK( c1.isHalted() == true );

        c1.restart();
        CHECK( c1.isHalted() == false );
        CHECK( c1.getProgramCounter() == 0 );
        CHECK( c1.getAccumulator() == 0 );

        c1.step();
        CHECK( c1.getProgramCounter() == 1 );
        CHECK( c1.getAccumulator() == 5 );
    }
