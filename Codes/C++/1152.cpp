#include<bits/stdc++.h>
using namespace std;
int cha[100000005];
signed main(){
	int n,t1,t2;
	scanf("%d%d",&n,&t1);
	for(int i=1;i<n;i++){scanf("%d",&t2);cha[(t2>t1)?(t2-t1):(t1-t2)]++;t1=t2;}
	for(int i=1;i<n;i++)if(!cha[i]){printf("Not jolly");return 0;}
	printf("Jolly");return 0;
}
