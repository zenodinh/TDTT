#include <iostream>
#include <stdlib.h>
using namespace std;

int CapNhat(int *a, int n, int T, int min)
{
    int k = T;
    for (int i = 0; i < n; ++i)
    {
        if (i != min)
        {
            if (a[i] - a[i - 1] > 1)
            {
                --a[i];
                --k;
            }
        }
    }
    return k;
}

int TamThuong(int *a, int n, int T)
{
    int min = 0;
    for (int i = 0; i < n; i++)
        if (a[min] > a[i])
            min = i;
    while (T > 0)
    {
        --a[min];
        --T;
        int k = CapNhat(a, n, T, min);
        if (k < 0)
            return a[min] + 1;
        T = k;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                cout << ", ";
            cout << a[i];
        }
        cout << "\tT = " << T << endl;
    }
    return a[min];
}

// int FindMin(int *array, int left, int right)
// {
//     if (left == right)
//         return left;
//     int mid = (left + right) / 2;
//     int i = FindMin(array, left, mid);
//     int j = FindMin(array, mid + 1, right);
//     return (array[i] < array[j]) ? i : j;
// }
int CaiTien(int *a, int n, int T)
{
    // int MinPos = FindMin(a, 0, n - 1);
    int MinPos = 0;
    for (int i = 0; i < n; i++)
        if (a[MinPos] > a[i])
            MinPos = i;
    int p = MinPos;
    while (T > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                cout << ", ";
            cout << a[i];
        }
        cout << "\tT = " << T << endl;
        if (p == MinPos && a[p] == a[p + 1])
        {
            --a[p];
            --T;
            ++p;
        }
        else if (p == MinPos)
        {
            ++p;
        }
        else if (p != MinPos)
        {
            if (p == MinPos + 1 && a[p] > a[p - 1])
            {
                --a[p];
                --T;
                ++p;
            }
            else if (a[p] - a[p - 1] > 1)
            {
                --a[p];
                --T;
                ++p;
            }
            else
                p = MinPos;
        }
    }
    return a[MinPos];
}

int main()
{
    int a[] = {1, 1, 1, 1};
    int b[] = {1, 2, 2, 1};
    int c[] = {1, 2, 2, 3, 3, 2, 2, 1};
    cout << TamThuong(a, 4, 3) << endl;
    cout << TamThuong(b, 4, 3) << endl;
    cout << TamThuong(c, 8, 6) << endl;
    cout << CaiTien(a, 4, 3) << endl;
    cout << CaiTien(b, 4, 3) << endl;
    cout << CaiTien(c, 8, 6) << endl;
}