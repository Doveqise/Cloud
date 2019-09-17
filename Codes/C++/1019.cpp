#include <bits/stdc++.h>
using namespace std;
int maxlen = 0, newlen = 0, n;
string str[22];
int ok[22];
int pp(string &str1, string &str2)
{
    if (str1.length() == 1)
    {
        if (str2[0] == str1[0])
            return str2.length();
        return 0;
    }
    else
    {
        for (int i = 1; i < str1.length(); i++)
        {
            string temp1 = str1.substr(str1.length() - i);
            string temp2 = str2.substr(0, i);
            if (temp1 == temp2)
                return str2.length() - i;
        }
    }
    return 0;
}
void dfs(string &s)
{
    for (int i = 0; i < n; i++)
    {
        int temp = pp(s, str[i]);
        if (temp && ok[i] < 2)
        {
            ok[i]++;
            newlen += temp;
            if (newlen > maxlen)
                maxlen = newlen;
            dfs(str[i]);
            ok[i]--;
            newlen -= temp;
        }
    }
}
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> str[i];
    string cr;
    cin >> cr;
    dfs(cr);
    cout << maxlen << endl;
    return 0;
}