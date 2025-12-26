#ifndef BSP_VISUALIZE_H
#define BSP_VISUALIZE_H

#include "BSPNode.h"
#include "Point.h"
#include "qcustomplot.h"
#include <vector>
#include <string>

void visualizeASCII(BSPNode *root,
                    const std::vector<Point> &points,
                    int gridSize = 50);

void printPartitionLines(BSPNode *root);

/**
 * Print partition lines in readable format.
 *
 * @param root Root of BSP tree
 */
void printPartitionLinesGUI(QTextEdit *graphLabel, BSPNode* root);

/**
 * Print ASCII grid showing partitions.
 *
 * @param root Root of BSP tree
 * @param points Original input points
 * @param gridSize Size of ASCII grid (default: 50)
 */
void visualizeGUI(QCustomPlot *graphPlot, BSPNode *root,
                  const std::vector<Point> &points);
#endif
