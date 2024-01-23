/**
 * @author Clayton Moeck
 * @brief Unit tests for Rectangle
 */

#include "Rectangle.h"


Rectangle::Rectangle(Point p1, Point p2) {
    double leftX, rightX, upperY, lowerY;
    if(p1.getX() < p2.getX()) {
        leftX = p1.getX();
        rightX = p2.getX();
    }
    else {
        leftX = p2.getX();
        rightX = p1.getX();
    }

    if(p1.getY() > p2.getY()) {
        upperY = p1.getY();
        lowerY = p2.getY();
    }
    else {
        upperY = p2.getY();
        lowerY = p1.getY();
    }

    upperLeftVertex = Point(leftX, upperY);
    width = rightX - leftX;
    height = upperY - lowerY;
}

Rectangle::Rectangle(Point p1, double heightValue, double widthValue) {
    upperLeftVertex = p1;
    height = heightValue;
    width = widthValue;
}

Point Rectangle::getUpperLeftVertex() const {
    return upperLeftVertex;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

double Rectangle::getArea() const {
    return height * width;
}

double Rectangle::getPerimeter() const {
    return (2 * height) + (2 * width);
}

Point Rectangle::getCenter() const {
    double leftX, upperY, rightX, lowerY, centerX, centerY;
    leftX = upperLeftVertex.getX();
    upperY = upperLeftVertex.getY();
    rightX = leftX + width;
    lowerY = upperY - height;
    centerX = (leftX + rightX) / 2;
    centerY = (upperY + lowerY) / 2;
    Point center(centerX, centerY);
    return center;
}

Rectangle& Rectangle::translate(double xAmount, double yAmount) {
    upperLeftVertex.translate(xAmount, yAmount);
    return *this;
}

bool Rectangle::contains(const Point& p) {
    double leftX, upperY, rightX, lowerY, pointX, pointY;
    leftX = upperLeftVertex.getX();
    upperY = upperLeftVertex.getY();
    rightX = leftX + width;
    lowerY = upperY - height;
    pointX = p.getX();
    pointY = p.getY();

    if (pointX >= leftX && pointX <= rightX && pointY >= lowerY && pointY <= upperY) {
        return true;
    }
    else
        return false;
}