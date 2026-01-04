#ifndef BSP_CORE_H
#define BSP_CORE_H

#include "BSPNode.h"
#include "Point.h"
#include <vector>

BSPNode *buildBSPTree(const std::vector<Point> &points,
                      int depth = 0,
                      int maxDepth = 10,
                      int threshold = 3);

void choosePartition(const std::vector<Point> &points,
                     int depth,
                     double &a, double &b, double &c);

bool isLeftOf(const Point &p, double a, double b, double c);

void splitPoints(const std::vector<Point> &points,
                 double a, double b, double c,
                 std::vector<Point> &leftPoints,
                 std::vector<Point> &rightPoints);

#endif
