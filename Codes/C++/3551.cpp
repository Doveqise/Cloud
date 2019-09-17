#include<bits/stdc++.h>
#define N 1000100
char chuan_er[N];
int s[N],pre[N];
bool qb[N<<1],*b=qb+N;
int now,ans[N],top;
int main(){
    int n,k,x;scanf("%d%d",&n,&k);
    scanf("%s",chuan_er+1);b[0]=1;
    for(int i=1;i<=n;i++){
        s[i]=(now+=(chuan_er[i]=='b')?-1:k);
        if(b[now]){x=i;
            for(int j=1;j<=k+1;j++,x=pre[x]) b[s[ans[++top]=x]]=0; 
            pre[i+1]=x;}
        else pre[i+1]=i;
        b[now]=1;
    }
    while(top){
        for(int i=1;i<=k+1;++i) printf("%d ",ans[top--]);
        printf("\n");
    }
}