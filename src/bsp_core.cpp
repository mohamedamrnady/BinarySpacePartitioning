#include "bsp_core.h"
#include <iostream>
#include <algorithm>

BSPNode *buildBSPTree(const std::vector<Point> &points,
                      int depth, int maxDepth, int threshold)
{
    std::cout << "TODO: Implement buildBSPTree" << std::endl;
    BSPNode *leaf = new BSPNode();
    leaf->isLeaf = true;
    leaf->points = points;
    return leaf;
}

void choosePartition(const std::vector<Point> &points, int depth,
                     double &a, double &b, double &c)
{
    std::cout << "TODO: Implement choosePartition" << std::endl;
    a = 1.0;
    b = 0.0;
    c = 0.0;
}

bool isLeftOf(const Point &p, double a, double b, double c)
{
    return (a * p.x + b * p.y + c) <= 0;
}

void splitPoints(const std::vector<Point> &points,
                 double a, double b, double c,
                 std::vector<Point> &leftPoints,
                 std::vector<Point> &rightPoints)
{
    std::cout << "TODO: Implement splitPoints" << std::endl;
    leftPoints = points;
}
