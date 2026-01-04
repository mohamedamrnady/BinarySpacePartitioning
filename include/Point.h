#ifndef POINT_H
#define POINT_H

struct Point
{
    double x;
    double y;

    Point();
    Point(double x, double y);

    void print() const;
};

#endif
