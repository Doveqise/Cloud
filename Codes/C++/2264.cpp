#include <bits/stdc++.h>
using namespace std;
string word[100 + 5];
char sen[1000 + 5];
int n, ans;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> word[i];
        for (int j = 0; j < word[i].length(); j++)
            word[i][j] = tolower(word[i][j]);
    }
    getchar();
    gets(sen);
    int len = strlen(sen);
    for (int i = 0; i < len; i++)
        sen[i] = tolower(sen[i]);
    for (int i = 1; i <=n; i++)
    {
        string k = "";
        int flg = 1;
        for (int j = 0; j < len; j++)
        {
            if (sen[j] == ' ' || sen[j] == '.' || sen[j] == ',')
            {
                if (word[i] == k && flg)
                {
                    ans++;
                    flg = 0;
                }
                if (sen[j] == '.')
                    flg = 1;
                k = "";
            }
            else
                k += sen[j];
        }
    }
    printf("%d\n", ans);
    return 0;
}