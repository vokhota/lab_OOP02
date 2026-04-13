#include "Triangle.h"

int main() {
    Point A, B, C;
    cout << "Введіть координати трикутника (x y):\n";
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    Triangle t(A, B, C);

    if (t.isDegenerate()) {
        cout << "Трикутник вироджений (площа = 0)." << endl;
        return 0;
    }

    int n;
    cout << "Скільки точок перевірити? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Point P;
        cout << "Введіть точку " << i+1 << " (x y): ";
        cin >> P.x >> P.y;

        if (t.contains(P))
            cout << "Точка належить трикутнику або його межі.\n";
        else
            cout << "Точка НЕ належить трикутнику.\n";
    }

    return 0;
}
