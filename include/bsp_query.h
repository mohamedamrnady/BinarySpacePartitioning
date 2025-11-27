#ifndef BSP_QUERY_H
#define BSP_QUERY_H

#include "BSPNode.h"
#include "Point.h"
#include <vector>

/**
 * Find which partition contains the given point.
 * 
 * @param queryPoint Point to search for
 * @param root Root of BSP tree
 * @return Pointer to leaf node containing point, nullptr if tree is null
 */
BSPNode* findPartition(const Point& queryPoint, BSPNode* root);

/**
 * Count total nodes in tree.
 * 
 * @param root Root of BSP tree
 * @return Total number of nodes
 */
int countNodes(BSPNode* root);

/**
 * Count leaf nodes in tree.
 * 
 * @param root Root of BSP tree
 * @return Number of leaf nodes
 */
int countLeaves(BSPNode* root);

/**
 * Get tree depth.
 * 
 * @param root Root of BSP tree
 * @return Maximum depth of tree
 */
int getTreeDepth(BSPNode* root);

/**
 * Print tree structure for debugging.
 * 
 * @param root Root of BSP tree
 * @param indent Indentation level (default: 0)
 */
void printTree(BSPNode* root, int indent = 0);

/**
 * Verify all points are in tree.
 * 
 * @param root Root of BSP tree
 * @param points Original input points
 * @return true if all points can be found
 */
bool verifyAllPoints(BSPNode* root, const std::vector<Point>& points);

#endif
