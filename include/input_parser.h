#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include "Point.h"
#include <vector>
#include <string>

/**
 * Read points from file.
 * 
 * File format:
 *   Line 1: N (number of points)
 *   Lines 2 to N+1: x y (space-separated doubles)
 * 
 * @param filename Path to input file
 * @return Vector of Point objects
 */
std::vector<Point> readPointsFromFile(const std::string& filename);

/**
 * Validate input points.
 *
 * @param points Points to check in
 * @param point Point to check
 * @return true if exists, false otherwise
 */
bool checkIfPointExists(const std::vector<Point> &points, Point point);

/**
 * Validate input points.
 * 
 * @param points Points to validate
 * @return true if valid, false otherwise
 */
bool validatePoints(const std::vector<Point>& points);

/**
 * Generate random points for testing.
 * 
 * @param count Number of points to generate
 * @param minX Minimum X coordinate
 * @param maxX Maximum X coordinate
 * @param minY Minimum Y coordinate
 * @param maxY Maximum Y coordinate
 * @return Vector of random Point objects
 */
std::vector<Point> generateRandomPoints(int count, 
                                        double minX, double maxX,
                                        double minY, double maxY);

#endif
