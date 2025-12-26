#include "mainwindow.h"
#include "input_parser.h"
#include "BSPNode.h"
#include "bsp_core.h"
#include "bsp_query.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"
#include "Point.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pickFile_clicked()
{
    QList<QCustomPlot *> graphWidgetList = ui->stackedWidget->widget(1)->findChildren<QCustomPlot *>();
    QCustomPlot* graphPlot = nullptr;

    if (!graphWidgetList.isEmpty()) {
        graphPlot = graphWidgetList.first();
        // You can now use the firstChild pointer
        qDebug() << "First child object name:" << graphPlot->objectName();
    } else {
        qDebug() << "No children found.";
    }

    // Open the file dialog and get the selected file name
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Text File"), // Dialog title
                                                    "",                  // Default directory (empty means current or last used)
                                                    tr("Text Files (*.txt);;All Files (*.*)")); // File filters

    // Check if the user selected a file
    if (!fileName.isEmpty()) {
        std::vector<Point> points = readPointsFromFile(fileName.toStdString());
        BSPNode* root = buildBSPTree(points);
        int depth = getTreeDepth(root);

        qDebug() << "Added Graph";
        graphPlot->addGraph();

        qDebug() << "Adding Data";

        double greatestX = 0;
        double greatestY = 0;
        double smallestX = 0;
        double smallestY = 0;

        for (size_t i = 0; i < points.size(); ++i)
        {
            if (points[i].x > greatestX) {
                greatestX = points[i].x;
            }
            if (points[i].y > greatestY) {
                greatestY = points[i].y;
            }
            if (points[i].x < greatestX) {
                smallestX = points[i].x;
            }
            if (points[i].y < greatestY) {
                smallestY = points[i].y;
            }
            graphPlot->graph(0)->addData(points[i].x, points[i].y);
            /*
            minX = std::min(minX, points[i].x);
            maxX = std::max(maxX, points[i].x);
            minY = std::min(minY, points[i].y);
            maxY = std::max(maxY, points[i].y);*/
        }

        int gridSize = greatestX > greatestY ? greatestX : greatestY;
        std::cout << "Grid Size: " << gridSize << std::endl;

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
            int col = (int)(t * (gridSize - 1) + 0.5);
            return clampInt(col, 0, gridSize - 1);
        };

        auto mapYToRow = [&](double y)
        {
            double t = (y - smallestY) / (greatestY - smallestY);
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
                QCPItemStraightLine *infLine = new QCPItemStraightLine(graphPlot);
                if (node->a == 1.0 && node->b == 0.0)
                {
                    // Vertical split: x = -c
                    int col = mapXToCol(-node->c);
                    infLine->point1->setCoords(1.5 * greatestX, col); // e.g., (2, 0)
                    infLine->point2->setCoords(-1.5 * greatestX, col); // e.g., (2, 1)

                }
                else if (node->a == 0.0 && node->b == 1.0)
                {
                    // Horizontal split: y = -c
                    int row = mapYToRow(-node->c);
                    infLine->point1->setCoords(row, 1.5 * greatestY); // e.g., (2, 0)
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

        qDebug() << "Changing Screen";
        ui->stackedWidget->setCurrentIndex(1);
        /*qDebug() << "Selected file path:" << fileName; // Pass the file path to your code (here, print to console)

        // *** Process the file path in your code ***
        // Example: Read the file's content
        std::vector<Point> points = readPointsFromFile(fileName);
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Cannot open file for reading:" << file.errorString();
            return;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            // Process each line as needed (e.g., store in a data structure, display in a QPlainTextEdit)
            qDebug() << "Read line:" << line;
        }

        file.close();*/
    } else {
        qDebug() << "File dialog cancelled or no file selected.";
    }
}

void MainWindow::on_home_clicked() {}

void MainWindow::on_graphPoints_clicked() {}

void MainWindow::on_pickPoints_clicked() {}
