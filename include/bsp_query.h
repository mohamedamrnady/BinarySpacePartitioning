#ifndef BSP_QUERY_H
#define BSP_QUERY_H

#include "BSPNode.h"
#include "Point.h"
#include <vector>

BSPNode *findPartition(const Point &queryPoint, BSPNode *root);

int countNodes(BSPNode *root);

int countLeaves(BSPNode *root);

int getTreeDepth(BSPNode *root);

void printTree(BSPNode *root, int indent = 0);

bool verifyAllPoints(BSPNode *root, const std::vector<Point> &points);

#endif
