#include "LittleComputer.h"

LittleComputer::LittleComputer() {
    accumulator = 0;
    programCounter = 0;
    for (int i = 0; i < 20; i++) {
        memory[i] = 0;
    }
}

LittleComputer::LittleComputer(int instructions[], int numberOfInstructions) {
    programCounter = 0;
    accumulator = 0;
    littleInstruction = 0;
    littleInstructionInfo = 0;


    for (int i = 0; i < numberOfInstructions; i++) {
        memory[i] = instructions[i];
    }

    if (numberOfInstructions < 20) {
        for (int i = numberOfInstructions; i < 20; i++) {
            memory[i] = 0;
        }
    }

}

int LittleComputer::getProgramCounter() {
    return programCounter;
}

int LittleComputer::getAccumulator() {
    return accumulator;
}

int LittleComputer::getMemoryAt(int locationNumber) {
    return memory[locationNumber];
}

int LittleComputer::getCurrentInstruction() {
    return memory[programCounter];
}

void LittleComputer::step() {
    if (memory[programCounter] != 0) {
        littleInstruction = memory[programCounter] / 100;
        littleInstructionInfo = memory[programCounter] % 100;
    
        programCounter++;
        LittleComputer::instructionCalculation(littleInstruction, littleInstructionInfo);

    }
}

bool LittleComputer::isHalted() {
    if (memory[programCounter] == 0) {
        return true;
    }
    else
        return false;
}

void LittleComputer::instructionCalculation(int& instruType, int& instruInfo) {
    if (instruType == 1) {
        LittleComputer::accumulatorAdd(instruInfo);
    }
    else if (instruType == 2) {
        LittleComputer::accumulatorSub(instruInfo);
    }
    else if (instruType == 3) {
        LittleComputer::storeInfo(instruInfo);
    }
    else if (instruType == 5) {
        LittleComputer::loadInfo(instruInfo);
    }
    else if (instruType == 6) {
        LittleComputer::alwaysBranch(instruInfo);
    }
    else if (instruType == 7) {
        LittleComputer::branchIf(instruInfo);
    }
}

void LittleComputer::accumulatorAdd(int& instruInfo) {
    accumulator += memory[instruInfo];
}

void LittleComputer::accumulatorSub(int& instruInfo) {
    accumulator -= memory[instruInfo];
}

void LittleComputer::storeInfo(int& instruInfo) {
    memory[instruInfo] = accumulator;
}

void LittleComputer::loadInfo(int& instruInfo) {
    accumulator = memory[instruInfo];
}

void LittleComputer::alwaysBranch(int& instruInfo) {
    programCounter = instruInfo;
}

void LittleComputer::branchIf(int& instruInfo) {
    if (accumulator == 0) {
        programCounter = instruInfo;
    }
}

void LittleComputer::restart() {
    accumulator = 0;
    programCounter = 0;
}