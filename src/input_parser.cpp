#include "input_parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

std::vector<Point> readPointsFromFile(const std::string &filename)
{
    std::cout << "TODO: Implement readPointsFromFile" << std::endl;

    std::vector<Point> points;

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return points;
    }

    int n;
    file >> n;

    for (int i = 0; i < n; i++)
    {
        double x, y;
        if (file >> x >> y)
        {
            points.push_back(Point(x, y));
        }
    }

    file.close();
    return points;
}

bool validatePoints(const std::vector<Point> &points)
{
    std::cout << "TODO: Implement validatePoints" << std::endl;

    return !points.empty();
}

std::vector<Point> generateRandomPoints(int count,
                                        double minX, double maxX,
                                        double minY, double maxY)
{
    std::cout << "TODO: Implement generateRandomPoints" << std::endl;

    std::vector<Point> points;

    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < count; i++)
    {
        double x = minX + (maxX - minX) * (rand() / static_cast<double>(RAND_MAX));
        double y = minY + (maxY - minY) * (rand() / static_cast<double>(RAND_MAX));
        points.push_back(Point(x, y));
    }

    return points;
}
