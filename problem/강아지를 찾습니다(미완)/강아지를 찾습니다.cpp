#include <cmath>
#include <iostream>
using namespace std;

struct {
    double x;
    double y;
} typedef Point;

Point trilateration(const Point& p1, const Point& p2, const Point& p3, double r1, double r2, double r3) {
    double A = 2 * (p2.x - p1.x);
    double B = 2 * (p2.y - p1.y);
    double C = pow(r1, 2) - pow(r2, 2) - pow(p1.x, 2) + pow(p2.x, 2) - pow(p1.y, 2) + pow(p2.y, 2);
    double D = 2 * (p3.x - p1.x);
    double E = 2 * (p3.y - p1.y);
    double F = pow(r1, 2) - pow(r3, 2) - pow(p1.x, 2) + pow(p3.x, 2) - pow(p1.y, 2) + pow(p3.y, 2);

    double x = (C * E - F * B) / (E * A - B * D);
    double y = (C * D - A * F) / (B * D - A * E);

    return {x, y};
}

int main() {
    Point p[3];
    Point ans;

    double r[3];

    for(int i = 0; i < 3; ++i) {
        cin >> p[i].x >> p[i].y;
        cin >> r[i];
    }

    ans = trilateration(p[0], p[1], p[2], r[0], r[1], r[2]);

    cout << ans.x << ' ' << ans.y;

    return 0;
}