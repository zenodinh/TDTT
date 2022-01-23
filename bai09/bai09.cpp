#include <iostream>
using namespace std;

void Xoa(string &a, int xoa)
{
    string before, after;
    before = a.substr(0, xoa);
    after = a.substr(xoa + 1, a.length() - xoa - 1);
    a = before + after;
}

bool TonTai(string s, char t)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] == t)
            return true;
    return false;
}

bool CaiTien(string s, string p)
{
    int s_pos, i;
    i = s_pos = 0;
    while (i < p.length() && s_pos < s.length())
    {
        if (s[s_pos] == p[i])
        {
            ++s_pos;
            ++i;
        }
        else if (p[i] == '*')
        {
            if (s[s_pos] != p[i - 1])
                return false;
            while (p[i - 1] == s[s_pos])
            {
                ++s_pos;
            }
            ++i;
        }
        else if (p[i] == '.')
        {
            if (TonTai(s, s[s_pos]) == 1)
                return false;
            else
                ++i;
        }
        else
        {
            if (p[i + 1] != '*')
                return false;
            if (i + 2 > p.length() - 1)
                return false;
            i += 2;
            if(p[i] == s[s_pos])
            {
                ++i;
                ++s_pos;
            }
            else return false;
        }
    }
    if (i < p.length() || s_pos < s.length())
        return false;
    return true;
}

int main()
{
    string s = "aab";
    string p = "c*a*b";
    cout << CaiTien(s, p) << endl;
}