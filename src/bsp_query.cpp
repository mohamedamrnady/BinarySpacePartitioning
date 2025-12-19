#include "bsp_query.h"
#include "bsp_core.h"
#include <iostream>
#include <algorithm> // for std::max

BSPNode *findPartition(const Point &queryPoint, BSPNode *root)
{
    if (!root)
        return nullptr; // Empty tree
    if (root->isLeaf)
        return root; // Leaf node

    // Recurse into left or right subtree
    if (isLeftOf(queryPoint, root->a, root->b, root->c))
    {
        return findPartition(queryPoint, root->left);
    }
    else
    {
        return findPartition(queryPoint, root->right);
    }
}

int countNodes(BSPNode *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(BSPNode *root)
{
    if (!root)
        return 0;
    if (root->isLeaf)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int getTreeDepth(BSPNode *root)
{
    if (!root)
        return 0;
    int leftDepth = getTreeDepth(root->left);
    int rightDepth = getTreeDepth(root->right);
    return 1 + std::max(leftDepth, rightDepth);
}

void printTree(BSPNode *root, int indent)
{
    if (!root)
        return;

    std::string spacer(indent * 2, ' ');

    if (root->isLeaf)
    {
        std::cout << spacer << "Leaf node: " << root->points.size() << " points\n";
        return;
    }

    // Internal node: show partition line
    std::cout << spacer << "Node: "
              << root->a << "x + " << root->b << "y + " << root->c << " = 0\n";

    // Recurse into children
    printTree(root->left, indent + 1);
    printTree(root->right, indent + 1);
}

bool verifyAllPoints(BSPNode *root, const std::vector<Point> &points)
{
    for (const Point &p : points)
    {
        BSPNode *leaf = findPartition(p, root);
        if (!leaf)
            return false;

        // Check if point is actually in leaf's point vector
        bool found = false;
        for (const Point &lp : leaf->points)
        {
            if (lp.x == p.x && lp.y == p.y)
            {
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }
    return true;
}
