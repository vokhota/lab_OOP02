#include "triangle.h"
#include <cmath>

double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heronArea(const Triangle &t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::area() const {
    return heronArea(*this);
}

bool isDegenerate(const Triangle &t) {
    return t.area() == 0;
}

static double cross(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}

static bool onSegment(const Point &A, const Point &B, const Point &P) {
    return fabs(cross(A, B, P)) < 1e-9 && 
           (P.x >= std::min(A.x, B.x) && P.x <= std::max(A.x, B.x)) &&
           (P.y >= std::min(A.y, B.y) && P.y <= std::max(A.y, B.y));
}

bool Triangle::contains(const Point &P) const {
    if (isDegenerate(*this)) {
        return onSegment(A, B, P) || onSegment(B, C, P) || onSegment(C, A, P);
    }

    double c1 = cross(A, B, P);
    double c2 = cross(B, C, P);
    double c3 = cross(C, A, P);

    bool has_neg = (c1 < 0) || (c2 < 0) || (c3 < 0);
    bool has_pos = (c1 > 0) || (c2 > 0) || (c3 > 0);

    return !(has_neg && has_pos);
}

bool isOnBoundary(const Triangle &T, const Point &P) {
    if (isDegenerate(T)) {
        return onSegment(T.A, T.B, P) || onSegment(T.B, T.C, P) || onSegment(T.C, T.A, P);
    }

    double c1 = cross(T.A, T.B, P);
    double c2 = cross(T.B, T.C, P);
    double c3 = cross(T.C, T.A, P);

    return (c1 == 0 || c2 == 0 || c3 == 0);
}