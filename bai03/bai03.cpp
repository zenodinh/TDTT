#include <iostream>
#include <stdlib.h>
using namespace std;

void TamThuong(int *a, int *b, int m, int n)
{
    int Min = 999999;
    int p, q;
    p = q = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            if (Min > abs(a[i] + b[j]))
            {
                Min = abs(a[i] + b[j]);
                p = i + 1;
                q = j + 1;
            }
        }
    }
    cout << p << " " << q << endl;
    return;
}

// Dùng cho quick sort tang dan
int phanDayCon(int *a, int l, int r)
{
    int navigate = a[r];
    int bienChayBenTrai = l, bienChayBenPhai = r - 1;

    do
    {
        while (a[bienChayBenTrai] < navigate)
            bienChayBenTrai++;
        while (a[bienChayBenPhai] > navigate)
            bienChayBenPhai--;

        if (bienChayBenTrai < bienChayBenPhai)
        {
            swap(a[bienChayBenTrai], a[bienChayBenPhai]);
            bienChayBenTrai++;
            bienChayBenPhai--;
        }
    } while (bienChayBenTrai < bienChayBenPhai);

    swap(a[bienChayBenTrai], a[r]);
    return bienChayBenTrai;
}

void quickSort(int *a, int l, int r)
{
    if (r - l <= 1)
    {
        if (a[r] < a[l])
            swap(a[l], a[r]);
        return;
    }
    else
    {
        int diemChia = phanDayCon(a, l, r);
        quickSort(a, l, diemChia - 1);
        quickSort(a, diemChia + 1, r);
    }
}

void CaiTien(int *a, int *b, int m, int n)
{
    int *SortArray = new int[m + n];
    for (int i = 0; i < n + m; ++i)
    {
        if (i < m)
            SortArray[i] = a[i];
        else
            SortArray[i] = b[i - m];
    }
    quickSort(SortArray, 0, m - 1);
    quickSort(SortArray, m, n + m - 1);

    // Thực hiện phần cải tiến
    int low = 0;
    int high = n + m - 1;
    int min = INT16_MAX;
    int p = 0, q = 0;
    while (true)
    {
        if (abs(SortArray[low] + SortArray[high]) < min)
        {
            min = abs(SortArray[low] + SortArray[high]);
            p = SortArray[low];
            q = SortArray[high];
        }
        if (min == 0)
            break;
        if (high > m && low < m - 1)
            (SortArray[low] + SortArray[high] > 0) ? high-- : low++;
        else if (high == m && low < m - 1)
            low++;
        else if (low == m - 1 && high > m)
            high--;
        else if (high == m && low == m - 1)
            break;
    }
    for (int i = 0; i < m; ++i)
        if (a[i] == p)
        {
            cout << i + 1 << " ";
            break;
        }
    for (int i = 0; i < n; ++i)
        if (b[i] == q)
        {
            cout << i + 1 << endl;
            break;
        }
}

int main()
{
    int a[] = {1, 8, 2, 9};
    int b[] = {-5, -6, 3, -7, -4};
    // TamThuong(a, b, 4, 5);
    CaiTien(a, b, 4, 5);
    return 1;
}