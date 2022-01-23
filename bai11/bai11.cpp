#include <iostream>
using namespace std;

int TamThuong(int *a, int k, int n, int m)
{
    int *max = new int[n + m];
    for (int i = 0; i < n + m; ++i)
        max[i] = -999999;

    int i, count;
    count = 0;
    while (count < n)
    {
        i = 0;
        while (i < k * 2)
        {
            if (a[i] > max[count] && count == 0)
                max[count] = a[i];
            else if (a[i] > max[count] && a[i] < max[count - 1])
                max[count] = a[i];
            i += 2;
        }
        ++count;
    }
    while (count < n + m)
    {
        i = 1;
        while (i < k * 2)
        {
            if (count == n && a[i] > max[count])
                max[count] = a[i];
            else if (a[i] > max[count] && a[i] < max[count - 1])
                max[count] = a[i];
            i += 2;
        }
        ++count;
    }
    int sum = 0;
    for (int i = 0; i < count; ++i)
        sum += max[i];
    delete[] max;
    return sum;
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

int CaiTien(int *a, int k, int n, int m)
{
    int *SortArray = new int[k];
    int sum = 0;

    for (int i = 0; i < k; i++)
        SortArray[i] = a[i * 2];

    quickSort(SortArray, 0, k - 1);

    for (int i = k - 1; i > k - 1 - n; --i)
        sum += SortArray[i];

    for (int i = 0; i < k; i++)
        SortArray[i] = a[i * 2 + 1];

    quickSort(SortArray, 0, k - 1);

    for (int i = k - 1; i > k - 1 - m; --i)
        sum += SortArray[i];
    return sum;
}

int main()
{
    int a[] = {4, 9, 3, 5, 7, 2, 5, 5};
    cout << TamThuong(a, 4, 2, 1) << endl;
    cout << CaiTien(a, 4, 2, 1) << endl;
}