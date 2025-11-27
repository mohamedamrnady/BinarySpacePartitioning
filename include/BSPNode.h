#ifndef BSPNODE_H
#define BSPNODE_H

#include <vector>
#include "Point.h"

/**
 * Node in a BSP tree.
 * 
 * Partition line equation: ax + by + c = 0
 * - Vertical line (x = k): a=1, b=0, c=-k
 * - Horizontal line (y = k): a=0, b=1, c=-k
 * 
 * Point classification: 
 * - Point (x,y) is "left" if ax + by + c <= 0
 * - Point (x,y) is "right" if ax + by + c > 0
 */
struct BSPNode {
    // Partition line coefficients
    double a, b, c;
    
    // Child nodes
    BSPNode* left;
    BSPNode* right;
    
    // Leaf node data
    std::vector<Point> points;  // Only filled for leaf nodes
    bool isLeaf;
    
    BSPNode();
    ~BSPNode();
};

#endif
