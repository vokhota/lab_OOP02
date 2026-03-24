#include <iostream>
#include "triangle.h"
using namespace std;

int main() {
    Triangle t;
    cout << "vvedut koordunatu trukutnuka (x1 y1 x2 y2 x3 y3): ";
    cin >> t.A.x >> t.A.y >> t.B.x >> t.B.y >> t.C.x >> t.C.y;

    if (isDegenerate(t)) {
        cout << "trukutnyk vrodgenuy" << endl;
        cout << "Programa vse odno bude pereviraty prinadlezhnist tochok do vrodgenu trukutnuka" << endl;
    } 
    cout << "vvedit tochku (x y), abo bud yakuy symvol dlya vihodu:" << endl;
    Point p;
    while (cin >> p.x >> p.y) {
        if (t.contains(p)) {
            cout << "tochka (" << p.x << ", " << p.y << ") nalezhit trukutnyku" << endl;
        } else {
            cout << "tochka (" << p.x << ", " << p.y << ") ne nalezhit trukutnyku" << endl;
        }

    }
    return 0;

}