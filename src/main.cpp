#include <iostream>
#include "Point.h"
#include "BSPNode.h"
#include "bsp_core.h"
#include "input_parser.h"
#include "bsp_query.h"
#include "bsp_visualize.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    std::cout << "=== BSP Tree Project ===" << std::endl;
    std::cout << "Reading points from '" << filename << "'..." << std::endl;

    std::vector<Point> points = readPointsFromFile(filename);
    std::cout << "Read " << points.size() << " points." << std::endl;

    std::cout << "\nBuilding BSP tree..." << std::endl;
    BSPNode *root = buildBSPTree(points);

    std::cout << "\nTree Statistics:" << std::endl;
    std::cout << "  Depth: " << getTreeDepth(root) << std::endl;
    std::cout << "  Total nodes: " << countNodes(root) << std::endl;
    std::cout << "  Leaf nodes: " << countLeaves(root) << std::endl;

    std::cout << "\nTree Structure:" << std::endl;
    printTree(root);

    std::cout << "\nVisualization:" << std::endl;
    visualizeASCII(root, points);

    if (!points.empty())
    {
        std::cout << "\nQuery Test:" << std::endl;
        Point testQuery = points[0];
        std::cout << "Searching for point (" << testQuery.x << ", " << testQuery.y << ")..." << std::endl;
        BSPNode *result = findPartition(testQuery, root);
        if (result)
        {
            std::cout << "Found in partition containing " << result->points.size() << " points." << std::endl;
        }
    }

    delete root;

    std::cout << "\nDone!" << std::endl;
    return 0;
}
