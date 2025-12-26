#ifndef POINT_H
#define POINT_H

/**
 * Represents a 2D point in space.
 */
struct Point {
    double x;
    double y;
    
    Point();
    Point(double x, double y);
    
    // Helper for printing
    void print() const;

    // Overload the equality operator
    bool operator==(const Point& other) const;
};

#endif
