#include "bsp_query.h"
#include "bsp_core.h"
#include <iostream>
#include <algorithm>

BSPNode* findPartition(const Point& queryPoint, BSPNode* root) {
    std::cout << "TODO: Implement findPartition" << std::endl;
    // Should:
    // 1. If root is null, return nullptr
    // 2. If root is leaf, return root
    // 3. Otherwise, use isLeftOf() to determine which child to recurse into
    // 4. Recursively search left or right subtree
    
    // Stub: Just return root
    return root;
}

int countNodes(BSPNode* root) {
    std::cout << "TODO: Implement countNodes" << std::endl;
    // Should recursively count all nodes (internal + leaf)
    // Base case: if root is nullptr, return 0
    // Recursive case: return 1 + countNodes(left) + countNodes(right)
    
    if (root == nullptr) return 0;
    return 1; // Stub: just count root
}

int countLeaves(BSPNode* root) {
    std::cout << "TODO: Implement countLeaves" << std::endl;
    // Should recursively count only leaf nodes
    // Base case: if root is nullptr, return 0
    // If root is leaf, return 1
    // Otherwise: return countLeaves(left) + countLeaves(right)
    
    if (root == nullptr) return 0;
    if (root->isLeaf) return 1;
    return 0; // Stub
}

int getTreeDepth(BSPNode* root) {
    std::cout << "TODO: Implement getTreeDepth" << std::endl;
    // Should recursively find maximum depth
    // Base case: if root is nullptr, return 0
    // Recursive case: return 1 + max(getTreeDepth(left), getTreeDepth(right))
    
    if (root == nullptr) return 0;
    return 1; // Stub: just return 1
}

void printTree(BSPNode* root, int indent) {
    std::cout << "TODO: Implement printTree" << std::endl;
    // Should print tree structure with indentation
    // For internal nodes: show partition line (a, b, c)
    // For leaf nodes: show number of points
    
    if (root == nullptr) return;
    
    // Stub: Print basic info
    for (int i = 0; i < indent; i++) std::cout << "  ";
    if (root->isLeaf) {
        std::cout << "Leaf: " << root->points.size() << " points" << std::endl;
    } else {
        std::cout << "Node: partition line " << root->a << "x + " 
                  << root->b << "y + " << root->c << " = 0" << std::endl;
    }
}

bool verifyAllPoints(BSPNode* root, const std::vector<Point>& points) {
    std::cout << "TODO: Implement verifyAllPoints" << std::endl;
    // Should:
    // 1. For each point in input vector
    // 2. Use findPartition() to locate it in tree
    // 3. Return false if any point is not found
    // 4. Return true if all points are found
    
    // Stub: just return true
    return true;
}
