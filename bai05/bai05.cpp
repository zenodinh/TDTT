#include <iostream>
using namespace std;

void TamThuong(string a, string b)
{
    for (int i = 0; i < a.length() - b.length() + 1; i++)
    {
        if (a.substr(i, b.length()) == b)
            cout << i << " ";
    }
}

void CaiTien(string a, string b, int i)
{
    if (i + b.length() == a.length())
    {
        if (a.substr(i, b.length()) == b)
            cout << i << " ";
        return;
    }
    if (a.substr(i, b.length()) == b)
        cout << i << " ";
    CaiTien(a, b, i + 1);
    return;
}

int main()
{
    string a = "Aaaaa";
    string b = "aa";
    // TamThuong(a, b);
    CaiTien(a, b, 0);
    return 0;
}