#ifndef POINT_H
#define POINT_H

struct Point
{
    double x;
    double y;

    Point();
    Point(double x, double y);

    void print() const;

    // Overload the equality operator
    bool operator==(const Point& other) const;
};

#endif
