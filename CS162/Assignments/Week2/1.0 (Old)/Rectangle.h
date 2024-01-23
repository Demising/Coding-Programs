#include "Point.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle {
public:

    /**
     * @brief Constructer that creates a Rectangle with 2 points.
     * @param p1 Point 1.
     * @param p2 Point 2.
     * @param upperLeftVertex A point used to identify which is the upper left corner of the rectangle.
     * @param leftX Variable to store the value of the smaller X value.
     * @param rightX Variable to store the value of the bigger X value.
     * @param upperY Variable to store the value of the bigger Y value.
     * @param lowerY Variable to store the value of the smaller Y value.
     * @param width Variable to store the width of the Rectangle, found by adding leftX to rightX.
     * @param height Variable to store the height of the Rectangle, found by subtracting upperY and lowerY.
     */
    Rectangle(Point p1, Point p2);

    /**
     * @brief Constructor that creates a Rectangle from a point, a height, and a width.
     * 
     * @param p1 Point 1
     * @param heightValue Value of the Rectangle's height.
     * @param widthValue Value of the Rectangle's width.
     * @param upperLeftVertex The point of p1 gets stored into the upperLeftVertex point.
     * @param width Value of widthValue is stored into the Rectangle's width.
     * @param height Value of heightValue is stored into the Rectangle's height.
     */
    Rectangle(Point p1, double heightValue, double widthValue);

    /**
     * @brief Moves the Rectangle the certain amount by moving it's upperLeftVertex.
     * @param xAmount The value we want to move the Rectangle on the X-axis.
     * @param yAmount The value we want to move the Rectangle on the Y-axis.
     * @param upperLeftVertex Variable is put through the translate function of the Point class, moving it's X and Y values accordingly to xAmount and yAmount.
     * @return Returns the reference of the rectangle, now moved.
     */
    Rectangle& translate(double xAmount, double yAmount);

    /**
     * @brief Get the Rectangle's width.
     * @return Rectangle's width. 
     */
    double getWidth() const;

    /**
     * @brief Get the Rectangle's height.
     * 
     * @return Rectangle's height. 
     */
    double getHeight() const;

    /**
     * @brief Get the point that is saved to upperLeftVertex.
     * 
     * @return Rectangle's upperLeftVertex.
     */
    Point getUpperLeftVertex() const;

    /**
     * @brief Find and return the center of the Rectangle
     * @param leftX Variable to store the value of the smaller X value.
     * @param rightX Variable to store the value of the bigger X value.
     * @param upperY Variable to store the value of the bigger Y value.
     * @param lowerY Variable to store the value of the smaller Y value.
     * 
     * @return Point 
     */
    Point getCenter() const;

    /**
     * @brief Find the area of the Rectangle.
     * @param width The width of the Rectangle.
     * @param height The height of the Rectangle.
     * @return width * height.
     */
    double getArea() const;

    /**
     * @brief Find the perimeter of the Rectangle.
     * @param width The width of the Rectangle.
     * @param height The height of the Rectangle.
     * @return (2 * width) + (2 * height). 
     */
    double getPerimeter() const;

    /**
     * @brief Find if point 'p' is within the Rectangle or not.
     * 
     * @param p Input point.
     * @param width Width of the Rectangle.
     * @param height Height of the Rectangle.
     * @param leftX Variable of Rectangle to store the value of the smaller X value.
     * @param rightX Variable of Rectangle to store the value of (width + leftX).
     * @param upperY Variable of Rectangle to store the value of the bigger Y value.
     * @param lowerY Variable of Rectangle to store the value of (upperY - height).
     * @param pointX Variable used to store the X value of point 'p'.
     * @param pointY Variable used to store the Y value of point 'p'.
     * @return true if point 'p' is in the Rectangle.
     * @return false if point 'p' is outside the Rectangle.
     */
    bool contains(const Point& p);

private:
    Point upperLeftVertex;
    
    double height;
    double width;
};

#endif