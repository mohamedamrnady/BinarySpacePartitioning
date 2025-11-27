#ifndef BSP_VISUALIZE_H
#define BSP_VISUALIZE_H

#include "BSPNode.h"
#include "Point.h"
#include <vector>
#include <string>

/**
 * Print ASCII grid showing partitions.
 * 
 * @param root Root of BSP tree
 * @param points Original input points
 * @param gridSize Size of ASCII grid (default: 50)
 */
void visualizeASCII(BSPNode* root, 
                    const std::vector<Point>& points,
                    int gridSize = 50);

/**
 * Print partition lines in readable format.
 * 
 * @param root Root of BSP tree
 */
void printPartitionLines(BSPNode* root);

#endif
