#include <bits/stdc++.h>
using namespace std;
char str[105];
signed main()
{
    int UP = 0, DWN = 0;
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    for (int i = 1; i <= len; i++)
    {
        if (str[i] <= 'z' && str[i] >= 'a')
            DWN++;
        else
            UP++;
    }
    if (UP <= DWN)
        for (int i = 1; i <= len; i++)
            str[i] = tolower(str[i]);
    else
        for (int i = 1; i <= len; i++)
            str[i] = toupper(str[i]);
    printf("%s", str + 1);
}