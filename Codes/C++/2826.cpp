#include<bits/stdc++.h>
using namespace std;
long long BIT1[100010],BIT2[100010],n,m,p1,p2,p3,p4;
void add(int pos,int num){
    p4=pos*num;
    for(;pos<=n;pos+=(pos&(-pos)))
        BIT1[pos]+=num,BIT2[pos]+=p4;
}
long long query1(int pos){
    long long ans=0;
    for(;pos;pos-=(pos&(-pos))) ans+=BIT1[pos];
    return ans;
}
long long query2(int pos){
    long long ans=0;
    for(;pos;pos-=(pos&(-pos))) ans+=BIT2[pos];
    return ans;
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&p1);
        add(i,p1);
    }
    for(int i=1;i<=m;++i){
        scanf("%lld%lld%lld",&p1,&p2,&p3);
        if(p1==1){
            add(p2,p3);
        }else{
            printf("%lld\n",(p3+1)*(query1(p3)-query1(p2-1))-query2(p3)+query2(p2-1));
        }
    }
    return 0;
}
