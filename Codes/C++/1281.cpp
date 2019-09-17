#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
int n,m,ans,flag;
stack<int>fir,sec;
bool check(int x){
	int sum=0,num=1;
	for(int i=n;i>0;i--){
		if(sum+a[i]>x){num++;sum=a[i];}
		else sum+=a[i];
	}
	return num<=m;
}
void print(){
	int now=0,tmp=n,cnt=0;
	for(int i=n;i>0;i--){
		if(now+a[i]>ans){fir.push(i+1);sec.push(tmp);tmp=i;now=a[i];cnt++;}
		else now+=a[i];
	}
	if(cnt!=m)fir.push(1),sec.push(tmp);
	while(!fir.empty()){printf("%d %d\n",fir.top(),sec.top());fir.pop();sec.pop();}
	return;
}
signed main(){
	int maxx=0,minn=1e9+7;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {scanf("%d",&a[i]);minn=min(minn,a[i]);maxx+=a[i];}
	while(minn<=maxx){
		int mid=(minn+maxx)>>1;
		if(check(mid)){ans=mid;maxx=mid-1;}
		else minn=mid+1;
	}
	print();
	return 0;
}
