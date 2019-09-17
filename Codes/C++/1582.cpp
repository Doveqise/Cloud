#include<bits/stdc++.h>
int lowbit(int n){return -n&n;}
int num_of_1(int x){int num=0;while(x){num++;x-=lowbit(x);}return num;}
signed main(){
	int n,k,ans;
    scanf("%d%d",&n,&k);
    while(num_of_1(n)>k)ans+=lowbit(n),n+=lowbit(n);
    printf("%d\n",ans);
    return 0;
}