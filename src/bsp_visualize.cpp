#include "bsp_visualize.h"
#include "qcustomplot.h"
#include <iostream>
#include <vector>
#include <algorithm>

void visualizeASCII(BSPNode *root,
                    const std::vector<Point> &points,
                    int gridSize)
{
    // Should:
    // 1. Find bounding box of all points
    // 2. Create gridSize x gridSize character grid
    // 3. Draw partition lines on grid
    // 4. Draw points on grid
    // 5. Print the grid

    std::cout << "ASCII Visualization:" << std::endl;

    if (gridSize < 5)
        gridSize = 5;

    if (points.empty())
    {
        std::cout << "[No points to visualize]" << std::endl;
        return;
    }

    // 1. Find bounding box of all points
    double minX = points[0].x, maxX = points[0].x;
    double minY = points[0].y, maxY = points[0].y;

    for (size_t i = 0; i < points.size(); ++i)
    {
        minX = std::min(minX, points[i].x);
        maxX = std::max(maxX, points[i].x);
        minY = std::min(minY, points[i].y);
        maxY = std::max(maxY, points[i].y);
    }

    // Avoid division by zero
    if (maxX - minX == 0.0)
    {
        minX -= 1.0;
        maxX += 1.0;
    }
    if (maxY - minY == 0.0)
    {
        minY -= 1.0;
        maxY += 1.0;
    }

    // 2. Create gridSize x gridSize character grid
    std::vector<std::vector<char>> grid(
        gridSize, std::vector<char>(gridSize, ' '));

    // Helper lambdas
    auto clampInt = [&](int v, int lo, int hi)
    {
        if (v < lo)
            return lo;
        if (v > hi)
            return hi;
        return v;
    };

    auto mapXToCol = [&](double x)
    {
        double t = (x - minX) / (maxX - minX);
        int col = (int)(t * (gridSize - 1) + 0.5);
        return clampInt(col, 0, gridSize - 1);
    };

    auto mapYToRow = [&](double y)
    {
        double t = (y - minY) / (maxY - minY);
        int rowFromBottom = (int)(t * (gridSize - 1) + 0.5);
        int row = (gridSize - 1) - rowFromBottom;
        return clampInt(row, 0, gridSize - 1);
    };

    // 3. Draw partition lines on grid (single symbol for consistency)
    std::vector<BSPNode *> stack;
    stack.push_back(root);

    while (!stack.empty())
    {
        BSPNode *node = stack.back();
        stack.pop_back();

        if (node == nullptr)
            continue;

        if (!node->isLeaf)
        {
            if (node->a == 1.0 && node->b == 0.0)
            {
                // Vertical split: x = -c
                int col = mapXToCol(-node->c);
                for (int r = 0; r < gridSize; ++r)
                    grid[r][col] = '#';
            }
            else if (node->a == 0.0 && node->b == 1.0)
            {
                // Horizontal split: y = -c
                int row = mapYToRow(-node->c);
                for (int c = 0; c < gridSize; ++c)
                    grid[row][c] = '#';
            }
        }

        stack.push_back(node->left);
        stack.push_back(node->right);
    }

    // 4. Draw points on grid
    for (size_t i = 0; i < points.size(); ++i)
    {
        int col = mapXToCol(points[i].x);
        int row = mapYToRow(points[i].y);
        grid[row][col] = '*';
    }

    // 5. Print the grid
    for (int r = 0; r < gridSize; ++r)
    {
        for (int c = 0; c < gridSize; ++c)
        {
            std::cout << grid[r][c];
        }
        std::cout << std::endl;
    }
}

void visualizeGUI(QCustomPlot *graphPlot, BSPNode *root,
                  const std::vector<Point> &points)
{
    double greatestX = 0;
    double greatestY = 0;
    double smallestX = 0;
    double smallestY = 0;

    graphPlot->clearItems();
    graphPlot->addGraph();
    graphPlot->graph(0)->data()->clear();

    for (size_t i = 0; i < points.size(); ++i)
    {
        if (points[i].x > greatestX)
        {
            greatestX = points[i].x;
        }
        if (points[i].y > greatestY)
        {
            greatestY = points[i].y;
        }
        if (points[i].x < greatestX)
        {
            smallestX = points[i].x;
        }
        if (points[i].y < greatestY)
        {
            smallestY = points[i].y;
        }
        graphPlot->graph(0)->addData(points[i].x, points[i].y);
    }

    int plotSize = greatestX > greatestY ? greatestX : greatestY;

    // Helper lambdas
    auto clampInt = [&](int v, int lo, int hi)
    {
        if (v < lo)
            return lo;
        if (v > hi)
            return hi;
        return v;
    };

    auto mapXToCol = [&](double x)
    {
        double t = (x - smallestX) / (greatestX - smallestX);
        int col = (int)(t * (plotSize - 1) + 0.5);
        return clampInt(col, 0, plotSize - 1);
    };

    auto mapYToRow = [&](double y)
    {
        double t = (y - smallestY) / (greatestY - smallestY);
        int rowFromBottom = (int)(t * (plotSize - 1) + 0.5);
        int row = (plotSize - 1) - rowFromBottom;
        return clampInt(row, 0, plotSize - 1);
    };

    // 3. Draw partition lines on grid (single symbol for consistency)
    std::vector<BSPNode *> stack;
    stack.push_back(root);

    while (!stack.empty())
    {
        BSPNode *node = stack.back();
        stack.pop_back();

        if (node == nullptr)
            continue;

        if (!node->isLeaf)
        {
            QCPItemStraightLine *infLine = new QCPItemStraightLine(graphPlot);
            if (node->a == 1.0 && node->b == 0.0)
            {
                // Vertical split: x = -c
                int col = mapXToCol(-node->c);
                infLine->point1->setCoords(1.5 * greatestX, col);  // e.g., (2, 0)
                infLine->point2->setCoords(-1.5 * greatestX, col); // e.g., (2, 1)
            }
            else if (node->a == 0.0 && node->b == 1.0)
            {
                // Horizontal split: y = -c
                int row = mapYToRow(-node->c);
                infLine->point1->setCoords(row, 1.5 * greatestY);  // e.g., (2, 0)
                infLine->point2->setCoords(row, -1.5 * greatestY); // e.g., (2, 1)
            }
        }

        stack.push_back(node->left);
        stack.push_back(node->right);
    }

    qDebug() << "Replotting";

    graphPlot->xAxis->setRange(-1.5 * greatestX, 1.5 * greatestX);
    graphPlot->yAxis->setRange(-1.5 * greatestY, 1.5 * greatestY);
    graphPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
    graphPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    graphPlot->replot();
}

void printPartitionLines(BSPNode *root)
{
    // Should:
    // 1. Traverse tree (pre-order or in-order)
    // 2. For each internal node, print partition line equation
    // 3. Format: "ax + by + c = 0" or more readable format
    //    e.g., "x = 5.0" for vertical lines, "y = 3.0" for horizontal
    // 1. Handle empty tree
    if (root == nullptr)
        return;
    // 2. If this is an internal node, print its partition line
    if (!root->isLeaf)
    {
        std::cout << "Partition: "
                  << root->a << "x + "
                  << root->b << "y + "
                  << root->c << " = 0";

        // 3. Print a more readable form
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
    // 4. Traverse left and right subtrees
    printPartitionLines(root->left);
    printPartitionLines(root->right);
}

void printPartitionLinesGUI(QTextEdit *graphLabel, BSPNode *root)
{
    // Should:
    // 1. Traverse tree (pre-order or in-order)
    // 2. For each internal node, print partition line equation
    // 3. Format: "ax + by + c = 0" or more readable format
    //    e.g., "x = 5.0" for vertical lines, "y = 3.0" for horizontal
    // 1. Handle empty tree

    if (root == nullptr)
        return;
    // 2. If this is an internal node, print its partition line
    if (!root->isLeaf)
    {
        graphLabel->setPlainText(graphLabel->toPlainText() + "Partition: " + QString::number(root->a) + "x + " + QString::number(root->b) + "y + " + QString::number(root->c) + " = 0\n");

        // 3. Print a more readable form
        if (root->a == 1.0 && root->b == 0.0)
        {
            graphLabel->setPlainText(graphLabel->toPlainText() + " (vertical line: x = " + QString::number(-root->c) + ")\n");
        }
        else if (root->a == 0.0 && root->b == 1.0)
        {
            graphLabel->setPlainText(graphLabel->toPlainText() + " (horizontal line: y = " + QString::number(-root->c) + ")\n");
        }
    }
    // 4. Traverse left and right subtrees
    printPartitionLinesGUI(graphLabel, root->left);
    printPartitionLinesGUI(graphLabel, root->right);
}
//!!!!!!!!!!!!!!IMPORTANT!!!!!!!!!!!!!!
/*
For main program implementer (Entry Point), I suggest a small function to print the grid size and points of the problem so it's easier to visualize or inspect.
However, the current visualizeASCII function successfully prints the grid with points as '*' and splitting lines as '#'.
*/
