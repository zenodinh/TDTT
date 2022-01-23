#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

struct circle
{
    int x, y, R;
};

double TamThuong(circle *a)
{
    double AB = sqrt((a[0].x * 1.0000 - a[1].x * 1.0000) * (a[0].x * 1.0000 - a[1].x * 1.0000) + (a[0].y * 1.0000 - a[1].y * 1.0000) * (a[0].y * 1.0000 - a[1].y * 1.0000));
    if (AB >= 2 * a[0].R || AB < 0)
        return 0.0;
    if (AB == 0.0)
        return 3.14159 * a[0].R * a[0].R;
    double AH = AB * 1.0000 / 2;
    double alpha = acos(AH * 1.0000 / a[0].R * 1.0000);
    alpha = alpha * 2;
    return alpha * a[0].R * a[0].R - a[0].R * a[0].R * sin(alpha);
}

int main()
{
    circle a[2];
    a[0].x = 1;
    a[0].y = 2;
    a[0].R = 2;
    a[1].x = 1;
    a[1].y = 2;
    a[1].R = 2;
    cout << TamThuong(a);
}