#include <bits/stdc++.h>
using namespace std;
string a, s[4617], d[4617];
char X[] = {'0', '2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '0', '7', '7', '8', '8', '8', '9', '9', '9', '0'}; //预处理
bool v;
signed main()
{
    cin >> a;
    for (int i = 0; i <= 4616; i++)
        cin >> s[i];
    for (int i = 0; i <= 4616; i++, d[i] = s[i])
    {
        d[0] = s[0];
        for (int j = 0; j <= s[i].size() - 1; j++)
            s[i][j] = X[s[i][j] - 'A' + 1];
    }
    for (int i = 0; i <= 4616; i++)
        if (s[i] == a)
            cout << d[i + (v = 1) - 1] << endl;
    if (!v)
        cout << "NONE" << endl;
}