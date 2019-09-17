#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
rope<int> str, rstr;
int n, m;
inline void reverse(int st, int ed){
    if (st >= ed + 1) return;
    ed++;
    rope<int> tmp = str.substr(st + str.begin(), ed + str.begin());
    str = str.substr(0 + str.begin(), st + str.begin()) + rstr.substr(n - ed + rstr.begin(), n - st + rstr.begin()) + str.substr(ed + str.begin(), str.length() + str.begin());
    rstr = rstr.substr(rstr.begin(), n - ed + rstr.begin()) + tmp + rstr.substr(n - st + rstr.begin(), rstr.length() + rstr.begin());
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i) str.append(i), rstr.append(n - i + 1);
    for (int i = 1,l,r; i <= m; ++i){
        scanf("%d%d",&l,&r);
        reverse(l - 1, r - 1);
    }
    for (int i = 0; i < (int)str.length(); ++i) printf("%d ", str[i]);
    return 0;
}