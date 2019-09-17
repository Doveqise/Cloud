#include<bits/stdc++.h>
#define eps 1e-6
using namespace std;
double score[100005],minn[100005],grade[100005],maxn,sum;
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%lf",&score[i]);sum+=score[i];}
    minn[n]=score[n];
    for(int i=n-1;i;i--)minn[i]=min(score[i],minn[i+1]);
    for(int i=1;i<=n-2;i++){
        sum-=score[i];
        grade[i]=(sum-minn[i+1])/(double)(n-i-1);
        maxn=max(grade[i],maxn);
    }
    for(int i=1;i<=n-2;i++) if(maxn-grade[i]<eps&&maxn-grade[i]>(-eps)) printf("%d\n", i);
    return 0;
}