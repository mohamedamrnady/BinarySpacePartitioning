#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcustomplot.h"
#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QString>
#include <QDebug> // For console output
#include <QFile> // For file operations
#include <QTextStream> // For reading file content

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QCustomPlot *graphPlot;
    QPushButton *home;
    QPushButton *graphPoints;

private slots:
    void on_home_clicked();
    void on_pickFile_clicked();
    void on_graphPoints_clicked();
    void on_pickPoints_clicked();
};
#endif // MAINWINDOW_H
