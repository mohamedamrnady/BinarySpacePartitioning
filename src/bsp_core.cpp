#include "bsp_core.h"
#include <iostream>
#include <algorithm>

BSPNode* buildBSPTree(const std::vector<Point>& points, 
                      int depth, int maxDepth, int threshold) {
    std::cout << "TODO: Implement buildBSPTree" << std::endl;
    // For now, just create a leaf with all points
    BSPNode* leaf = new BSPNode();
    leaf->isLeaf = true;
    leaf->points = points;
    return leaf;
}

void choosePartition(const std::vector<Point>& points, int depth,
                     double& a, double& b, double& c) {
    std::cout << "TODO: Implement choosePartition" << std::endl;
    // Default: vertical split at x=0
    // Strategy should be:
    // - Even depth: split on X axis (vertical line)
    // - Odd depth: split on Y axis (horizontal line)
    // - Use median value for split position
    a = 1.0; 
    b = 0.0; 
    c = 0.0;
}

bool isLeftOf(const Point& p, double a, double b, double c) {
    // This function is complete - it's the mathematical definition
    return (a * p.x + b * p.y + c) <= 0;
}

void splitPoints(const std::vector<Point>& points,
                 double a, double b, double c,
                 std::vector<Point>& leftPoints,
                 std::vector<Point>& rightPoints) {
    std::cout << "TODO: Implement splitPoints" << std::endl;
    // Should use isLeftOf() to classify each point
    // For now, just put all points in left
    leftPoints = points;
}
