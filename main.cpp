#include "include/mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>

#include "include/Point.h"
#include "include/BSPNode.h"
#include "include/bsp_core.h"
#include "include/input_parser.h"
#include "include/bsp_query.h"
#include "include/bsp_visualize.h"

int main(int argc, char *argv[])
{
    // Check arguments
    /*
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }*/

    /*std::string filename = argv[1];

    std::cout << "=== BSP Tree Project ===" << std::endl;
    std::cout << "Reading points from '" << filename << "'..." << std::endl;

    // Read points
    std::vector<Point> points = readPointsFromFile(filename);
    std::cout << "Read " << points.size() << " points." << std::endl;

    // Build tree
    std::cout << "\nBuilding BSP tree..." << std::endl;
    BSPNode* root = buildBSPTree(points);

    // Statistics
    std::cout << "\nTree Statistics:" << std::endl;
    std::cout << "  Depth: " << getTreeDepth(root) << std::endl;
    std::cout << "  Total nodes: " << countNodes(root) << std::endl;
    std::cout << "  Leaf nodes: " << countLeaves(root) << std::endl;

    // Print tree structure
    std::cout << "\nTree Structure:" << std::endl;
    printTree(root);

    // Visualize
    std::cout << "\nVisualization:" << std::endl;
    visualizeASCII(root, points);

    // Test query (if we have points)
    if (!points.empty()) {
        std::cout << "\nQuery Test:" << std::endl;
        Point testQuery = points[0];
        std::cout << "Searching for point (" << testQuery.x << ", " << testQuery.y << ")..." << std::endl;
        BSPNode *result = findPartition(testQuery, root);
        if (result)
        {
            std::cout << "Found in partition containing " << result->points.size() << " points." << std::endl;
        }
    }

    // Cleanup
    delete root;

    std::cout << "\nDone!" << std::endl;
*/
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "BinarySpacePartitioningGUI_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
