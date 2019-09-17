#include <bits/stdc++.h>
using namespace std;
int num[500010],maxn,minn,sum,flag;
void dfs(int remain,int now,int goal,int maxx){
    int i;if(!remain){printf("%d\n",goal);flag=1;return;}
    if(now==goal){dfs(remain-1,0,goal,maxn);return;}
    for(i=maxx;i>=minn;i--)
        if(num[i]&&i+now<=goal){
            num[i]--;dfs(remain,now+i,goal,i);num[i]++;
        	if((!now)||now+i==goal) return;
        }
}
int main(){
    int i,k,n,temp;
    scanf("%d",&n);
    while(n){
    	flag=0;sum=0;maxn=minn=0;
    	memset(num,0,sizeof(num));
    	for(i=1;i<=n;i++){
        	scanf("%d",&k);
        	if(k<=50){
        	    sum+=k;
        	    num[k]++;
        	    minn=min(k,minn);
    	        maxn=max(k,maxn);
        	}
    	}
    	temp=sum/2;
    	for(i=maxn;i<=temp;i++){if(sum%i==0)dfs(sum/i,0,i,maxn);if(flag)break;}
    	if(!flag)printf("%d\n",sum);
    	scanf("%d",&n);
    }
    return 0;
}