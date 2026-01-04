#include "BSPNode.h"

BSPNode::BSPNode() : a(0.0), b(0.0), c(0.0), left(nullptr), right(nullptr), isLeaf(false) {}

BSPNode::~BSPNode()
{
    if (left != nullptr)
    {
        delete left;
        left = nullptr;
    }
    if (right != nullptr)
    {
        delete right;
        right = nullptr;
    }
}
