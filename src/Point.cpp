#include "../include/Point.h"
#include <iostream>

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double x, double y) : x(x), y(y) {}

void Point::print() const {
    std::cout << "(" << x << ", " << y << ")";
}
