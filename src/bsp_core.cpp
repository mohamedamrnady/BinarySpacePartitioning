#include "../include/bsp_core.h"
#include <limits>

using namespace std;

BSPNode *buildBSPTree(const vector<Point> &points,
                      int depth, int maxDepth, int threshold)
{
    // cout << "TODO: Implement buildBSPTree" << endl;

    // Check stopping criteria (depth, point count)
    if (points.size() <= static_cast<unsigned long>(threshold) || depth >= maxDepth)
    {
        BSPNode *leaf = new BSPNode();
        leaf->isLeaf = true;
        leaf->points = points;
        return leaf;
    }

    // choose partition line using choosePartition()
    double a, b, c;
    choosePartition(points, depth, a, b, c);
    // split points using splitPoints()
    vector<Point> left, right;
    splitPoints(points, a, b, c, left, right);
    // recursively build left and right subtrees
    BSPNode *node = new BSPNode();
    node->isLeaf = false;
    node->a = a;
    node->b = b;
    node->c = c;
    node->left = buildBSPTree(left, depth + 1, maxDepth, threshold);
    node->right = buildBSPTree(right, depth + 1, maxDepth, threshold);
    return node;
}

void choosePartition(const vector<Point> &points, int depth,
                     double &a, double &b, double &c)
{
    double mean, max = -numeric_limits<double>::infinity(), min = numeric_limits<double>::infinity();
    // - Odd depth: split on Y axis (horizontal line)
    if (depth % 2)
    { // false = 0 = even, true = 1 = odd
        // get mean of range
        for (const Point &p : points)
        {
            if (p.y > max)
                max = p.y;
            else if (p.y < min)
                min = p.y;
        }
        mean = (max + min) / 2;
        a = 0;
        b = 1;
    }
    // - Even depth: split on X axis (vertical line)
    else
    {
        // get mean of range
        for (const Point &p : points)
        {
            if (p.x > max)
                max = p.x;
            else if (p.x < min)
                min = p.x;
        }
        mean = (max + min) / 2;
        a = 1;
        b = 0;
    }
    c = -mean;
}

bool isLeftOf(const Point &p, double a, double b, double c)
{
    return (a * p.x + b * p.y + c) <= 0;
}

void splitPoints(const vector<Point> &points,
                 double a, double b, double c,
                 vector<Point> &leftPoints,
                 vector<Point> &rightPoints)
{
    for (const Point &p : points)
    {
        if (isLeftOf(p, a, b, c))
            leftPoints.push_back(p);
        else
            rightPoints.push_back(p);
    }
}
