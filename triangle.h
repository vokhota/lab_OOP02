#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

class Triangle {
private:
    Point A, B, C;
    double area(const Point &p1, const Point &p2, const Point &p3) const;

public:
    Triangle(Point a, Point b, Point c);
    bool isDegenerate() const;
    bool contains(const Point &P) const;
};

#endif

