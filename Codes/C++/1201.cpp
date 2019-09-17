#include <bits/stdc++.h>
using namespace std;
string nm[20];
map<string, int> mp;
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> nm[i];
    string nam;
    int ymn, ren;
    for(int i=1;i<=n;i++)
    {
        cin >> nam >> ymn >> ren;
        if(!ren)
            continue;
        int pjmn = ymn / ren;
        ymn = pjmn * ren;
        mp[nam] -= ymn;
        for (int i = 1; i <= ren; i++)
        {
            cin >> nam;
            mp[nam] += pjmn;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << nm[i] << " " << mp[nm[i]] << endl;
}