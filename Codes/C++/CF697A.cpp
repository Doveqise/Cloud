#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,s,x;
    scanf("%d%d%d",&t,&s,&x);
    x-=t;
    if(x<s&&x) printf("NO");
    else if(!(x%s)||!(x%s-1)) printf("YES");
    else printf("NO");
    return 0;
}
