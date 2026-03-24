#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
    double area() const;
    bool contains(const Point &P) const;
};

double distance(const Point &p1, const Point &p2);
double heronArea(const Triangle &t);
bool isDegenerate(const Triangle &t);

#endif
