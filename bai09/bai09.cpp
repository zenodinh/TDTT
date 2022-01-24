#include <iostream>
using namespace std;

bool CaiTien(string s, string p)
{
    int s_pos, i;
    i = s_pos = 0;
    char c = '.';
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
            if (c == '.')
                c = s[i];
            else if (s[i] == c)
            {
                s_pos++;
                i++;
            }
            else
                return false;
        }
        else
        {
            if (p[i + 1] != '*')
                return false;
            if (i + 2 > p.length() - 1)
                return false;
            i += 2;
            if (p[i] == s[s_pos])
            {
                ++i;
                ++s_pos;
            }
            else
                return false;
        }
    }
    if (i < p.length() || s_pos < s.length())
        return false;
    return true;
}

int main()
{
    string a, b;
    freopen("input.txt", "rt", stdin);
    getline(cin, a);
    getline(cin, b);
    freopen("con", "r", stdin);

    if (CaiTien(a, b) == 1)
        cout << "True\n";
    else
        cout << "False\n";
}