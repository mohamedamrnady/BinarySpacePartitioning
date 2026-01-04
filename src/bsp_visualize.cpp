#include "bsp_visualize.h"
#include <iostream>
#include <vector>
#include <algorithm>

void visualizeASCII(BSPNode *root,
                    const std::vector<Point> &points,
                    int gridSize)
{
    std::cout << "TODO: Implement visualizeASCII" << std::endl;

    std::cout << "ASCII Visualization:" << std::endl;
    std::cout << "[Visualization not yet implemented]" << std::endl;
    std::cout << "Points count: " << points.size() << std::endl;
}

void printPartitionLines(BSPNode *root)
{
    std::cout << "TODO: Implement printPartitionLines" << std::endl;

    if (root == nullptr)
        return;

    if (!root->isLeaf)
    {
        std::cout << "Partition: " << root->a << "x + "
                  << root->b << "y + " << root->c << " = 0";

        if (root->a == 1.0 && root->b == 0.0)
        {
            std::cout << " (vertical line: x = " << -root->c << ")";
        }
        else if (root->a == 0.0 && root->b == 1.0)
        {
            std::cout << " (horizontal line: y = " << -root->c << ")";
        }
        std::cout << std::endl;
    }
}
