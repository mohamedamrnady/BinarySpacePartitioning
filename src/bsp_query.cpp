#include "bsp_query.h"
#include "bsp_core.h"
#include <iostream>
#include <algorithm>

BSPNode *findPartition(const Point &queryPoint, BSPNode *root)
{
    std::cout << "TODO: Implement findPartition" << std::endl;

    return root;
}

int countNodes(BSPNode *root)
{
    std::cout << "TODO: Implement countNodes" << std::endl;

    if (root == nullptr)
        return 0;
    return 1;
}

int countLeaves(BSPNode *root)
{
    std::cout << "TODO: Implement countLeaves" << std::endl;

    if (root == nullptr)
        return 0;
    if (root->isLeaf)
        return 1;
    return 0;
}

int getTreeDepth(BSPNode *root)
{
    std::cout << "TODO: Implement getTreeDepth" << std::endl;

    if (root == nullptr)
        return 0;
    return 1;
}

void printTree(BSPNode *root, int indent)
{
    std::cout << "TODO: Implement printTree" << std::endl;

    if (root == nullptr)
        return;

    for (int i = 0; i < indent; i++)
        std::cout << "  ";
    if (root->isLeaf)
    {
        std::cout << "Leaf: " << root->points.size() << " points" << std::endl;
    }
    else
    {
        std::cout << "Node: partition line " << root->a << "x + "
                  << root->b << "y + " << root->c << " = 0" << std::endl;
    }
}

bool verifyAllPoints(BSPNode *root, const std::vector<Point> &points)
{
    std::cout << "TODO: Implement verifyAllPoints" << std::endl;

    return true;
}
