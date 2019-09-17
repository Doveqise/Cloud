#include<bits/stdc++.h>
using namespace std;
int n,k,minn=1e9,ch,head=1,tail=1,cnt;
int C[105];
struct ball{
	int pla,col;
}B[1000005];
bool cmp(ball a,ball b){
	return a.pla<b.pla;
}
signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		int ti;scanf("%d",&ti);
		for(int j=1;j<=ti;j++){
			scanf("%d",&B[++ch].pla);
			B[ch].col=i;
		}
	}
	sort(B+1,B+ch+1,cmp);
	C[B[1].col]=1;cnt=1;
	for(int i=2;i<=n;i++){
		if(B[i].pla==B[i-1].pla){
			tail++;
			C[B[i].col]++;
			if(C[B[i].col]==1)cnt++;
		}
		else break;
	}
	while(head<=n&&tail<=n){
		if(cnt==k){
			minn=min(minn,B[tail].pla-B[head].pla);
			C[B[head].col]--;
			if(C[B[head].col]==0)cnt--;
			head++;
			if(head>n) break;
			while(B[head].pla==B[head-1].pla){
				C[B[head].col]--;
				if(C[B[head].col]==0)cnt--;
				head++;
				if(head>n) break;
			}
		}
		else{
			tail++;
			if(tail>n) break;
			C[B[tail].col]++;
			if(C[B[tail].col]==1) cnt++;
			while(B[tail].pla==B[tail+1].pla){
				tail++;
				if(tail>n) break;
				C[B[tail].col]++;
				if(C[B[tail].col]==1)cnt++;
			}
		}
	}
	printf("%d",minn);
	return 0;
}

