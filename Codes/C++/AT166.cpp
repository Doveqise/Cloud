#include<bits/stdc++.h>
using namespace std;
int m1,d1,m2,d2,ans;
int daynum[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
    scanf("%d%d%d%d",&m1,&d1,&m2,&d2);
    while(m1!=m2){ans+=daynum[m1];++m1;}
    ans+=d2-d1;
    printf("%d",ans);
    return 0;
}
