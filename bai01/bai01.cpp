#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int TamThuong(int *a, int k, int n)
{
    int temp = 0;
    int max = 0;
    for (int i = 0; i < n - k; i++)
    {
        temp = a[i];
        for (int j = i + 1; j < i + k; j++)
            temp = __gcd(temp, a[j]);
        if (max < temp)
            max = temp;
    }
    return max;
}

int UCLN(int *a, int left, int right)
{
    int max = 1;
    int Length = left;
    for (int i = left; i <= right; ++i)
        if (a[Length] < a[i])
            Length = i;
    int *divisor = new int[a[Length] + 1];
    for (int i = 0; i <= a[Length]; ++i)
        divisor[i] = 0;
    for (int i = left; i <= right; ++i)
    {
        for (int j = 1; j <= sqrt(a[i]); ++j)
        {
            if (a[i] % j == 0)
                divisor[j]++;
            if (j != a[i] / j)
                divisor[a[i] / j]++;
        }
    }
    for (int i = a[Length]; i > 0; --i)
    {
        if (divisor[i] > right - left)
        {
            max = i;
            break;
        }
    }
    delete[] divisor;
    return max;
}

int CaiTien(int *a, int k, int n, int i)
{
    if (i + k == n)
        return UCLN(a, i, i + k - 1);
    int x = UCLN(a, i, i + k - 1);
    int y = CaiTien(a, k, n, i + 1);
    // cout << i << " --> " << i + k - 1 << ":= " << x << endl;
    return (x > y) ? x : y;
}

int main()
{
    int a[] = {2, 6, 4, 3, 18, 12, 24, 8, 7, 5};
    // cout << TamThuong(a, 3, 10);
    cout << CaiTien(a, 3, 10, 0) << endl;
    return 0;
}