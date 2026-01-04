#ifndef BSPNODE_H
#define BSPNODE_H

#include <vector>
#include "Point.h"

struct BSPNode
{
    double a, b, c;

    BSPNode *left;
    BSPNode *right;

    std::vector<Point> points;
    bool isLeaf;

    BSPNode();
    ~BSPNode();
};

#endif
