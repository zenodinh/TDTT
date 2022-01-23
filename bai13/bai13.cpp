#include <iostream>
using namespace std;

struct point
{
    int x;
    int y;

    bool operator==(const point &p) const
    {
        return x == p.x && y == p.y;
    }
    bool operator!=(const point &p) const
    {
        return !(*this == p);
    }
};

void TamThuong(point *a, int n)
{
    int so_diem_cung_phia = 0, count;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            count = 0;
            cout << "duong thang " << i << " --- " << j << "\n";
            for (int k = 0; k < n; ++k)
            {
                if (k != i && k != j)
                {
                    if ((a[i].y - a[j].y) * (a[k].x - a[i].x) + (a[j].x - a[i].x) * (a[k].y - a[i].y) > 0)
                        ++count;
                    cout << "   + (" << a[k].x << ", " << a[k].y << ") = " << (a[i].y - a[j].y) * (a[k].x - a[i].x) + (a[j].x - a[i].x) * (a[k].y - a[i].y) << endl;
                }
            }
            cout << count << " diem\n";
            if (count == (n - 2) / 2)
            {
                cout << i << "  " << j << endl;
                return;
            }
        }
    }
}

int Side(point m, point n, point *a, int left, int right)
{
    if (left == right)
    {
        if (a[left] == m || a[left] == n)
            return 0;
        return ((m.y - n.y) * (a[left].x - m.x) + (n.x - m.x) * (a[left].y - m.y) > 0) ? 1 : -1;
    }
    int mid = (left + right) / 2;
    int sum1 = Side(m, n, a, left, mid);
    int sum2 = Side(m, n, a, mid + 1, right);
    return sum1 + sum2;
}

void CaiTien(point *a, int n)
{
    int so_diem_cung_phia = 0, count;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            count = 0;
            if (Side(a[i], a[j], a, 0, n - 1) == 0)
            {
                cout << i << "  " << j << endl;
                return;
            }
        }
    }
}

int main()
{
    int num[] = {3, 5, 1, 3, 3, 1, 6, 1, 8, 3, 6, 5};
    point a[6];
    int i = 0;
    while (i < 12)
    {
        if (i % 2 == 0)
            a[i / 2].x = num[i];
        else
            a[i / 2].y = num[i];
        ++i;
    }
    // TamThuong(a, 6);
    CaiTien(a, 6);
}