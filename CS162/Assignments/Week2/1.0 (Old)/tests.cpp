/**
 * @author Clayton Moeck
 * @brief Unit tests for Rectangle
 */

//-----------------------------------------------------------------------------------
//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this line
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#define NOGDI

#include "doctest.h"
#include "Rectangle.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;
//-----------------------------------------------------------------------------------

//Sample functions
//Tests
TEST_CASE( " Testing Rectangle / Point / Width / Height " ) {
    Point p1(7, 4);
    Rectangle r1(p1, 8, 3);

    Point temp = r1.getUpperLeftVertex();
    REQUIRE( temp.isSameAs(p1) == true );

    CHECK( r1.getHeight() == Approx(8) );
    CHECK( r1.getWidth() == Approx(3) );

}

TEST_CASE( " Testing getArea / Point / Width / Height " ) {
    Point p1;
    Rectangle r1(p1, 4, 8);
    Rectangle r2(p1, 5, 12);

    CHECK( r1.getArea() == Approx(4 * 8) );
    CHECK( r2.getArea() == Approx(5 * 12) );
}

TEST_CASE( " Testing getPerimeter / Point / Width / Height " ) {
    Point p1;
    Rectangle r1(p1, 4, 7);
    Rectangle r2(p1, 2, 24);

    CHECK( r1.getPerimeter() == Approx(22) );
    CHECK( r2.getPerimeter() == Approx(52) );
    CHECK( r1.getPerimeter() == Approx((2 * 4) + (2 * 7)) );
    CHECK( r2.getPerimeter() == Approx((2 * 2) + (24 * 2)) );
}

TEST_CASE( " Testing getCenter / Point / Width / Height " ) {
    Point p1;
    Point p2(12, 6);
    Rectangle r1(p1, 4, 7);
    Rectangle r2(p2, 8, 4);

    Point temp1 = r1.getCenter();
    Point temp2 = r2.getCenter();

    CHECK( temp1.getX() == Approx( ((7 + p1.getX()) + p1.getX()) / 2) );
    CHECK( temp1.getY() == Approx( ((p1.getY() - 4) + p1.getY()) / 2) );
    CHECK( temp2.getX() == Approx( ((4 + p2.getX()) + p2.getX()) / 2) );
    CHECK( temp2.getY() == Approx( ((p2.getY() - 8) + p2.getY()) / 2) );
}

TEST_CASE( " Testing translate / Point / Width / Height " ) {
    Point p1(4, 17);
    Point p2(12, 9);
    Rectangle r1(p1, 6, 9);
    Rectangle r2(p2, 8, 6);

    /* CHECK( r1.getHeight() == Approx(6) );
    CHECK( r1.getWidth() == Approx(9) );
    CHECK( r2.getHeight() == Approx(8) );
    CHECK( r2.getWidth() == Approx(6) ); */

    r1.translate(3, 7);
    r2.translate(6, 8);

    CHECK( r1.getUpperLeftVertex().getX() == Approx(7) );
    CHECK( r1.getUpperLeftVertex().getY() == Approx(24) );
    CHECK( r2.getUpperLeftVertex().getX() == Approx(18) );
    CHECK( r2.getUpperLeftVertex().getY() == Approx(17) );

    /* CHECK( r1.getHeight() == Approx(6) );
    CHECK( r1.getWidth() == Approx(9) );
    CHECK( r2.getHeight() == Approx(8) );
    CHECK( r2.getWidth() == Approx(6) ); */

    r1.translate(-3, -7);
    r2.translate(-6, -8);

    CHECK( r1.getUpperLeftVertex().getX() == Approx(4) );
    CHECK( r1.getUpperLeftVertex().getY() == Approx(17) );
    CHECK( r2.getUpperLeftVertex().getX() == Approx(12) );
    CHECK( r2.getUpperLeftVertex().getY() == Approx(9) );

    /* CHECK( r1.getHeight() == Approx(6) );
    CHECK( r1.getWidth() == Approx(9) );
    CHECK( r2.getHeight() == Approx(8) );
    CHECK( r2.getWidth() == Approx(6) ); */

    r1.translate(-1, 3);
    r2.translate(2, -6);

    CHECK( r1.getUpperLeftVertex().getX() == Approx(3) );
    CHECK( r1.getUpperLeftVertex().getY() == Approx(20) );
    CHECK( r2.getUpperLeftVertex().getX() == Approx(14) );
    CHECK( r2.getUpperLeftVertex().getY() == Approx(3) );

    /* CHECK( r1.getHeight() == Approx(6) );
    CHECK( r1.getWidth() == Approx(9) );
    CHECK( r2.getHeight() == Approx(8) );
    CHECK( r2.getWidth() == Approx(6) ); */
}

TEST_CASE( " Testing contains / Point / Width / Height " ) {
    Point p1(4, 17);
    Point p2(12, 9);
    Rectangle r1(p1, 6, 9);
    Rectangle r2(p2, 8, 6);

    Point pointTest1(12, 14);
    Point pointTest2(21, 3);
    Point pointTest3(13, 14);
    Point pointTest4(10, 25);
    Point pointTest5(12, 1);
    Point pointTest6(15, 9);
    Point pointTest7(18, 9);

    CHECK( r1.contains(pointTest1) == true );
    CHECK( r1.contains(pointTest2) == false );
    CHECK( r1.contains(pointTest3) == true );
    CHECK( r1.contains(pointTest4) == false );
    CHECK( r1.contains(pointTest5) == false );
    CHECK( r1.contains(pointTest6) == false );
    CHECK( r1.contains(pointTest7) == false );

    CHECK( r2.contains(pointTest1) == false );
    CHECK( r2.contains(pointTest2) == false );
    CHECK( r2.contains(pointTest3) == false );
    CHECK( r2.contains(pointTest4) == false );
    CHECK( r2.contains(pointTest5) == true );
    CHECK( r2.contains(pointTest6) == true );
    CHECK( r2.contains(pointTest7) == true );
}

TEST_CASE( " Testing Rectangle / Point 1 / Point 2 " ) {
    Point p1(7, 4);
    Point p2(13, 9);
    Rectangle r1(p1, p2);

    Point tempUp1 = r1.getUpperLeftVertex();
    REQUIRE( tempUp1.getX() == 7 );
    REQUIRE( tempUp1.getY() == 9 );

    CHECK( r1.getHeight() == Approx(5) );
    CHECK( r1.getWidth() == Approx(6) );

}

TEST_CASE( " Testing getArea / Point 1 / Point 2 " ) {
    Point p1(23, 15);
    Point p2(13, 11);
    Point p3(31, 17);
    Point p4(17, 32);

    Rectangle r1(p1, p2);
    Rectangle r2(p3, p4);
    Rectangle r3(p2, p4);
    Rectangle r4(p1, p4);
    Rectangle r5(p1, p3);
    Rectangle r6(p2, p3);

    CHECK( r1.getArea() == Approx(10 * 4) );
    CHECK( r2.getArea() == Approx(14 * 15) );
    CHECK( r3.getArea() == Approx(4 * 21) );
    CHECK( r4.getArea() == Approx(6 * 17) );
    CHECK( r5.getArea() == Approx(8 * 2) );
    CHECK( r6.getArea() == Approx(18 * 6) );
}

TEST_CASE( " Testing getPerimeter / Point 1 / Point 2 " ) {
    Point p1(23, 15);
    Point p2(13, 11);
    Point p3(31, 17);
    Point p4(17, 32);

    Rectangle r1(p1, p2);
    Rectangle r2(p3, p4);
    Rectangle r3(p2, p4);
    Rectangle r4(p1, p4);
    Rectangle r5(p1, p3);
    Rectangle r6(p2, p3);

    CHECK( r1.getPerimeter() == Approx((10 * 2) + (4 * 2)) );
    CHECK( r2.getPerimeter() == Approx((14 * 2) + (15 * 2)) );
    CHECK( r3.getPerimeter() == Approx((4 * 2) + (21 * 2)) );
    CHECK( r4.getPerimeter() == Approx((6 * 2) + (17 * 2)) );
    CHECK( r5.getPerimeter() == Approx((8 * 2) + (2 * 2)) );
    CHECK( r6.getPerimeter() == Approx((18 * 2) + (6 * 2)) );
}

TEST_CASE( " Testing getCenter / Point 1 / Point 2 " ) {
    Point p1(23, 15);
    Point p2(13, 11);
    Point p3(31, 17);
    Point p4(17, 32);

    Rectangle r1(p1, p2);
    Rectangle r2(p3, p4);
    Rectangle r3(p2, p4);
    Rectangle r4(p1, p4);
    Rectangle r5(p1, p3);
    Rectangle r6(p2, p3);

    Point temp1 = r1.getCenter();
    Point temp2 = r2.getCenter();
    Point temp3 = r3.getCenter();
    Point temp4 = r4.getCenter();
    Point temp5 = r5.getCenter();
    Point temp6 = r6.getCenter();

    CHECK( temp1.getX() == Approx( ((10 + p2.getX()) + p2.getX()) / 2) );
    CHECK( temp1.getY() == Approx( ((p1.getY() - 4) + p1.getY()) / 2) );
    CHECK( temp2.getX() == Approx( ((14 + p4.getX()) + p4.getX()) / 2) );
    CHECK( temp2.getY() == Approx( ((p4.getY() - 15) + p4.getY()) / 2) );
    CHECK( temp3.getX() == Approx( ((4 + p2.getX()) + p2.getX()) / 2) );
    CHECK( temp3.getY() == Approx( ((p4.getY() - 21) + p4.getY()) / 2) );
    CHECK( temp4.getX() == Approx( ((6 + p4.getX()) + p4.getX()) / 2) );
    CHECK( temp4.getY() == Approx( ((p4.getY() - 17) + p4.getY()) / 2) );
    CHECK( temp5.getX() == Approx( ((8 + p1.getX()) + p1.getX()) / 2) );
    CHECK( temp5.getY() == Approx( ((p3.getY() - 2) + p3.getY()) / 2) );
    CHECK( temp6.getX() == Approx( ((18 + p2.getX()) + p2.getX()) / 2) );
    CHECK( temp6.getY() == Approx( ((p3.getY() - 6) + p3.getY()) / 2) );
}

TEST_CASE( " Testing translate / Point 1 / Point 2 " ) {
    Point p1(4, 17);
    Point p2(12, 20);
    Point p3(7, 5);
    Point p4(-2, 7);
    Rectangle r1(p1, p2);
    Rectangle r2(p3, p4);

    /* CHECK( r1.getHeight() == Approx(3) );
    CHECK( r1.getWidth() == Approx(8) );
    CHECK( r2.getHeight() == Approx(2) );
    CHECK( r2.getWidth() == Approx(9) ); */

    r1.translate(3, 7);
    r2.translate(6, 8);

    CHECK( r1.getUpperLeftVertex().getX() == Approx(7) );
    CHECK( r1.getUpperLeftVertex().getY() == Approx(27) );
    CHECK( r2.getUpperLeftVertex().getX() == Approx(4) );
    CHECK( r2.getUpperLeftVertex().getY() == Approx(15) );

    /* CHECK( r1.getHeight() == Approx(3) );
    CHECK( r1.getWidth() == Approx(8) );
    CHECK( r2.getHeight() == Approx(2) );
    CHECK( r2.getWidth() == Approx(9) ); */

    r1.translate(-3, -7);
    r2.translate(-6, -8);

    CHECK( r1.getUpperLeftVertex().getX() == Approx(4) );
    CHECK( r1.getUpperLeftVertex().getY() == Approx(20) );
    CHECK( r2.getUpperLeftVertex().getX() == Approx(-2) );
    CHECK( r2.getUpperLeftVertex().getY() == Approx(7) );

    /* CHECK( r1.getHeight() == Approx(3) );
    CHECK( r1.getWidth() == Approx(8) );
    CHECK( r2.getHeight() == Approx(2) );
    CHECK( r2.getWidth() == Approx(9) ); */

    r1.translate(-7, 8);
    r2.translate(-7, -6);

    CHECK( r1.getUpperLeftVertex().getX() == Approx(-3) );
    CHECK( r1.getUpperLeftVertex().getY() == Approx(28) );
    CHECK( r2.getUpperLeftVertex().getX() == Approx(-9) );
    CHECK( r2.getUpperLeftVertex().getY() == Approx(1) );

    /* CHECK( r1.getHeight() == Approx(3) );
    CHECK( r1.getWidth() == Approx(8) );
    CHECK( r2.getHeight() == Approx(2) );
    CHECK( r2.getWidth() == Approx(9) ); */
}

TEST_CASE( " Testing contains / Point 1 / Point 2 " ) {
    Point p1(23, 15);
    Point p2(13, 11);
    Point p3(31, 17);
    Point p4(17, 32);

    Rectangle r1(p1, p2);
    Rectangle r2(p3, p4);
    Rectangle r3(p2, p4);

    Point pointTest1(12, 14);
    Point pointTest2(21, 3);
    Point pointTest3(13, 14);
    Point pointTest4(10, 25);
    Point pointTest5(12, 1);
    Point pointTest6(28, 17);
    Point pointTest7(18, 14);

    CHECK( r1.contains(pointTest1) == false );
    CHECK( r1.contains(pointTest2) == false );
    CHECK( r1.contains(pointTest3) == true );
    CHECK( r1.contains(pointTest4) == false );
    CHECK( r1.contains(pointTest5) == false );
    CHECK( r1.contains(pointTest6) == false );
    CHECK( r1.contains(pointTest7) == true );

    CHECK( r2.contains(pointTest1) == false );
    CHECK( r2.contains(pointTest2) == false );
    CHECK( r2.contains(pointTest3) == false );
    CHECK( r2.contains(pointTest4) == false );
    CHECK( r2.contains(pointTest5) == false );
    CHECK( r2.contains(pointTest6) == true );
    CHECK( r2.contains(pointTest7) == false );

    CHECK( r3.contains(pointTest1) == false );
    CHECK( r3.contains(pointTest2) == false );
    CHECK( r3.contains(pointTest3) == true );
    CHECK( r3.contains(pointTest4) == false );
    CHECK( r3.contains(pointTest5) == false );
    CHECK( r3.contains(pointTest6) == false );
    CHECK( r3.contains(pointTest7) == false );
}