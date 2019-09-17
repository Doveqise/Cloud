#include<bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
int n,m,num[maxn];
int main(){
	while (scanf("%d%d",&n,&m)&&n&&m){
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++){int a;scanf("%d",&a);num[a-1]++;}
		int ans1=0,ans2=0,sum=0;
		for(int i=0;i<m;i++){
			if(num[i]>=3) ans1+=num[i]*(num[i]-1)*(num[i]-2)/6;
			for(int j=i+1;j<m;j++) for(int k=j+1;k<m;k++) 
				ans1+=num[i]*num[j]*num[k];
		}
		for(int i=0;i<m;i++){sum+=num[i];}
		for(int i=0;i<m;i++){
			if(num[i]>=3){
				int tmp=num[i]*(num[i]-1)*(num[i]-2)/6;	
				ans2+=tmp*(sum-num[i]);
				ans2+=tmp*(num[i]-3)/4;
			}
		}
		for(int i=0;i<m;i++) for(int j=i+1;j<m;j++) for(int k=j+1;k<m;k++) {
			ans2+=num[i]*(num[i]-1)/2*num[j]*num[k];
			ans2+=num[i]*num[j]*(num[j]-1)/2*num[k];
			ans2+=num[i]*num[j]*num[k]*(num[k]-1)/2;	
		}
		for(int i=0;i<m;i++) for(int j=i+1;j<m;j++) for(int k=j+1;k<m;k++) for(int l=k+1;l<m;l++){
			ans2+=num[i]*num[j]*num[k]*num[l];
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
