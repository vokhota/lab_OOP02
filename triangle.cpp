#include "Triangle.h"

Triangle::Triangle(Point a, Point b, Point c) {
    A = a; B = b; C = c;
}

double Triangle::area(const Point &p1, const Point &p2, const Point &p3) const {
    return fabs( (p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y)) / 2.0 );
}

bool Triangle::isDegenerate() const {
    return area(A, B, C) < 1e-9;
}

bool Triangle::contains(const Point &P) const {
    double S = area(A, B, C);        
    double S1 = area(P, B, C);       
    double S2 = area(A, P, C);
    double S3 = area(A, B, P);

    return fabs(S - (S1 + S2 + S3)) < 1e-9;
}
