#include "input_parser.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

std::vector<Point> readPointsFromFile(const std::string &filename)
{
    std::vector<Point> points;

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return points;
    }

    int n = 0;

    if (!(file >> n))
    {
        std::cerr << "Error: Could not read number of points from file" << std::endl;
        file.close();
        return points;
    }

    if (n <= 0)
    {
        std::cerr << "Error: Number of points must be positive, got " << n << std::endl;
        file.close();
        return points;
    }

    for (int i = 0; i < n; i++)
    {
        double x, y;
        if (file >> x >> y)
        {
            points.push_back(Point(x, y));
        }
        else
        {
            std::cerr << "Error: Could not read point " << (i + 1)
                      << " from file (expected " << n << " points)" << std::endl;
            file.close();
            return points;
        }
    }

    file.close();

    if (static_cast<int>(points.size()) != n)
    {
        std::cerr << "Error: Read " << points.size()
                  << " points but expected " << n << std::endl;
        return points;
    }

    return points;
}

bool validatePoints(const std::vector<Point> &points)
{

    if (points.empty())
    {
        std::cerr << "Error: Points vector is empty" << std::endl;
        return false;
    }

    for (size_t i = 0; i < points.size(); i++)
    {
        double x = points[i].x;
        double y = points[i].y;

        if (std::isnan(x) || std::isnan(y))
        {
            std::cerr << "Error: Point " << i << " contains NaN" << std::endl;
            return false;
        }

        if (std::isinf(x) || std::isinf(y))
        {
            std::cerr << "Error: Point " << i << " contains infinity" << std::endl;
            return false;
        }
    }

    return true;
}

std::vector<Point> generateRandomPoints(int count,
                                        double minX, double maxX,
                                        double minY, double maxY)
{
    std::vector<Point> points;

    if (count <= 0)
    {
        std::cerr << "Error: Count must be positive, got " << count << std::endl;
        return points;
    }

    if (minX >= maxX)
    {
        std::cerr << "Error: minX (" << minX << ") must be less than maxX (" << maxX << ")" << std::endl;
        return points;
    }

    if (minY >= maxY)
    {
        std::cerr << "Error: minY (" << minY << ") must be less than maxY (" << maxY << ")" << std::endl;
        return points;
    }

    static bool seedInitialized = false;
    if (!seedInitialized)
    {
        srand(static_cast<unsigned>(time(nullptr)));
        seedInitialized = true;
    }

    for (int i = 0; i < count; i++)
    {
        double x = minX + (maxX - minX) * (rand() / static_cast<double>(RAND_MAX));
        double y = minY + (maxY - minY) * (rand() / static_cast<double>(RAND_MAX));
        points.push_back(Point(x, y));
    }

    return points;
}
