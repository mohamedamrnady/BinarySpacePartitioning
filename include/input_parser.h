#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include "Point.h"
#include <vector>
#include <string>

std::vector<Point> readPointsFromFile(const std::string &filename);

bool validatePoints(const std::vector<Point> &points);
bool checkIfPointExists(const std::vector<Point> &points, Point point);

std::vector<Point> generateRandomPoints(int count,
                                        double minX, double maxX,
                                        double minY, double maxY);

#endif
