#ifndef BSP_CORE_H
#define BSP_CORE_H

#include "BSPNode.h"
#include "Point.h"
#include <vector>

/**
 * Build BSP tree from input points using recursive subdivision.
 * 
 * @param points Input points to partition
 * @param depth Current recursion depth (default: 0)
 * @param maxDepth Maximum tree depth before forcing leaf (default: 10)
 * @param threshold Minimum points to continue splitting (default: 3)
 * @return Root node of BSP tree
 */
BSPNode* buildBSPTree(const std::vector<Point>& points, 
                      int depth = 0, 
                      int maxDepth = 10, 
                      int threshold = 3);

/**
 * Choose partition line for given points.
 * Strategy: Axis-aligned median split (alternates X/Y by depth)
 * 
 * @param points Points to partition
 * @param depth Current depth (even = split on X, odd = split on Y)
 * @param a Output: partition line coefficient a
 * @param b Output: partition line coefficient b  
 * @param c Output: partition line coefficient c
 */
void choosePartition(const std::vector<Point>& points, 
                     int depth,
                     double& a, double& b, double& c);

/**
 * Check which side of partition line a point is on.
 * 
 * @param p Point to check
 * @param a Partition line coefficient a
 * @param b Partition line coefficient b
 * @param c Partition line coefficient c
 * @return true if point is on left/below (ax + by + c <= 0), false otherwise
 */
bool isLeftOf(const Point& p, double a, double b, double c);

/**
 * Split points based on partition line.
 * 
 * @param points Points to split
 * @param a Partition line coefficient a
 * @param b Partition line coefficient b
 * @param c Partition line coefficient c
 * @param leftPoints Output: points on left/below partition
 * @param rightPoints Output: points on right/above partition
 */
void splitPoints(const std::vector<Point>& points,
                 double a, double b, double c,
                 std::vector<Point>& leftPoints,
                 std::vector<Point>& rightPoints);

#endif
