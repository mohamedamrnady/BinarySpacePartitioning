#include "bsp_visualize.h"
#include <iostream>
#include <vector>
#include <algorithm>

void visualizeASCII(BSPNode* root, 
                    const std::vector<Point>& points,
                    int gridSize) {
    std::cout << "TODO: Implement visualizeASCII" << std::endl;
    // Should:
    // 1. Find bounding box of all points
    // 2. Create gridSize x gridSize character grid
    // 3. Draw partition lines on grid
    // 4. Draw points on grid
    // 5. Print the grid
    
    // Stub: Print a simple placeholder
    std::cout << "ASCII Visualization:" << std::endl;
    std::cout << "[Visualization not yet implemented]" << std::endl;
    std::cout << "Points count: " << points.size() << std::endl;
}

void printPartitionLines(BSPNode* root) {
    std::cout << "TODO: Implement printPartitionLines" << std::endl;
    // Should:
    // 1. Traverse tree (pre-order or in-order)
    // 2. For each internal node, print partition line equation
    // 3. Format: "ax + by + c = 0" or more readable format
    //    e.g., "x = 5.0" for vertical lines, "y = 3.0" for horizontal
    
    if (root == nullptr) return;
    
    // Stub: Print basic info
    if (!root->isLeaf) {
        std::cout << "Partition: " << root->a << "x + " 
                  << root->b << "y + " << root->c << " = 0";
        
        // Make it more readable
        if (root->a == 1.0 && root->b == 0.0) {
            std::cout << " (vertical line: x = " << -root->c << ")";
        } else if (root->a == 0.0 && root->b == 1.0) {
            std::cout << " (horizontal line: y = " << -root->c << ")";
        }
        std::cout << std::endl;
    }
}
