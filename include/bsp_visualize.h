#ifndef BSP_VISUALIZE_H
#define BSP_VISUALIZE_H

#include "BSPNode.h"
#include "Point.h"
#include <vector>
#include <string>

void visualizeASCII(BSPNode *root,
                    const std::vector<Point> &points,
                    int gridSize = 50);

void printPartitionLines(BSPNode *root);

#endif
