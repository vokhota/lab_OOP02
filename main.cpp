#include <iostream>
#include "triangle.h"
#include <cmath>
using namespace std;

bool containsHeron(const Triangle &t, const Point &P) {
    Triangle t1{t.A, t.B, P};
    Triangle t2{t.B, t.C, P};
    Triangle t3{t.C, t.A, P};
    double total = heronArea(t1) + heronArea(t2) + heronArea(t3);
    return fabs(total - heronArea(t)) < 1e-5;
}

int main() {
    Triangle t;
    cout << "Enter triangle coordinates (x1 y1 x2 y2 x3 y3): ";
    cin >> t.A.x >> t.A.y >> t.B.x >> t.B.y >> t.C.x >> t.C.y;


    cout << "Enter points (x y), or any symbol to finish:" << endl;
    Point p;
    while (cin >> p.x >> p.y) {
    
        if (t.contains(p)) {
            if (isOnBoundary(t, p)) {
                cout << "[Vector] Point (" << p.x << ", " << p.y << ") is ON the border." << endl;
            } else {
                cout << "[Vector] Point (" << p.x << ", " << p.y << ") is INSIDE." << endl;
            }
        } else {
            cout << "[Vector] Point (" << p.x << ", " << p.y << ") is OUTSIDE." << endl;
        }

        if (containsHeron(t, p)) {
            cout << "[Heron] Point (" << p.x << ", " << p.y << ") is INSIDE or ON border." << endl;
        } else {
            cout << "[Heron] Point (" << p.x << ", " << p.y << ") is OUTSIDE." << endl;
        }
    }

    return 0;
}

