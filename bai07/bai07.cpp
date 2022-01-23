#include <iostream>
using namespace std;

int HigherPoint(int *a, int n, int t)
{
    for (int i = t + 1; i < n; ++i)
        if (a[i] >= a[t])
            return i;
    return -1;
}

int TamThuong(int *a, int n)
{
    int sum = 0;
    int count = 0;
    int end = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        count = 0;
        if (a[i] > 0)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (a[j] < a[i])
                    count += a[i] - a[j];
                else if (a[j] >= a[i] && j > end)
                {
                    sum += count;
                    end = j;
                    break;
                }
                else if (a[j] >= a[i] && j <= end)
                    break;
            }
        }
    }
    return sum;
}

int CaiTien(int *a, int n)
{
    int LuongMua = 0, i = 0, count = 0, start = 0, end = HigherPoint(a, n, start);
    while (i < n)
    {
        if (end < start)
        {
            ++i;
            start = i;
            count = 0;
            end = HigherPoint(a, n, start);
        }
        else
        {
            ++i;
            if (i == end)
            {
                LuongMua += count;
                cout << start << " --> " << end << ": ";
                cout << LuongMua << endl;
                start = i;
                count = 0;
                end = HigherPoint(a, n, start);
            }
            else if (a[i] < a[start])
                count += a[start] - a[i];
        }
    }
    return LuongMua;
}

int main()
{
    int a[] = {1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int b[] = {4, 2, 0, 3, 2, 5};
    cout << TamThuong(a, 11) << endl;
    cout << TamThuong(b, 6) << endl;
    // cout << CaiTien(a, 11) << endl;
    // cout << CaiTien(b, 6) << endl;
    
}
