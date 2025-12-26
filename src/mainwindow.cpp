#include "mainwindow.h"
#include "input_parser.h"
#include "BSPNode.h"
#include "bsp_core.h"
#include "bsp_visualize.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"
#include "Point.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->hide();

    home = new QPushButton("Home", this);
    ui->statusbar->addPermanentWidget(home); // Adds to the right, stretch factor 0
    connect(home, &QPushButton::clicked, this, &MainWindow::on_home_clicked);

    graphPoints = new QPushButton("Graph Points", this);
    ui->statusbar->addWidget(graphPoints); // Adds to the right, stretch factor 0
    connect(graphPoints, &QPushButton::clicked, this, &MainWindow::on_graphPoints_clicked);
    graphPoints->hide();

    ui->stackedWidget->setCurrentIndex(0);

    QList<QCustomPlot *> graphWidgetList = ui->stackedWidget->widget(1)->findChildren<QCustomPlot *>();

    if (!graphWidgetList.isEmpty()) {
        graphPlot = graphWidgetList.first();
        // You can now use the firstChild pointer
        qDebug() << "First child object name:" << graphPlot->objectName();
    } else {
        qDebug() << "No children found.";
    }

    graphPlot->addGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pickFile_clicked()
{

    // Open the file dialog and get the selected file name
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Text File"), // Dialog title
                                                    "",                  // Default directory (empty means current or last used)
                                                    tr("Text Files (*.txt);;All Files (*.*)")); // File filters

    // Check if the user selected a file
    if (!fileName.isEmpty()) {
        std::vector<Point> points = readPointsFromFile(fileName.toStdString());
        BSPNode* root = buildBSPTree(points);
        visualizeGUI(graphPlot, root, points);

        qDebug() << "Changing Screen";
        ui->stackedWidget->setCurrentIndex(1);
        ui->statusbar->show();
    } else {
        qDebug() << "File dialog cancelled or no file selected.";
    }
}

void MainWindow::on_home_clicked() {
    ui->statusbar->hide();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_graphPoints_clicked() {
    ui->statusbar->show();
    graphPoints->hide();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pickPoints_clicked() {
    ui->statusbar->show();
    graphPoints->show();
    ui->stackedWidget->setCurrentIndex(2);
}
