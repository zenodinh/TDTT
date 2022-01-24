#include <iostream>
#include <string>
using namespace std;

bool onlyBit(int a)
{
    while (a > 0)
    {
        if (a % 10 > 1)
            return false;
        a /= 10;
    }
    return true;
}

int TamThuong(int x)
{
    int i = 1;
    while (onlyBit(i * x) == 0 && i * x < 1000000000)
    {
        ++i;
    }
    return i * x;
}

int ConvertStringToInt(string array)
{
    int sum = 0;
    for (int i = 0; i < array.size(); ++i)
        sum = (sum + int(array[i]) - 48) * 10;
    return sum / 10;
}

void IncreaseByOne(string &array)
{
    int nho = 1;
    for (int i = array.size() - 1; i > -1; --i)
    {
        if (array[i] == '0' && nho == 1)
        {
            array[i] = '1';
            nho = 0;
        }
        else if (array[i] == '1' && nho == 1)
            array[i] = '0';
    }
    if (nho == 1)
        array.insert(0, 1, '1');
}

int CaiTien(int x)
{
    string multiple;
    multiple = "0";
    while (true)
    {
        IncreaseByOne(multiple);
        int temp = ConvertStringToInt(multiple);
        if (temp % x == 0)
            return temp;
    }
}

int main()
{
    int a = 6;
    // cout << TamThuong(a) << endl;
    cout << CaiTien(a) << endl;
}