/*#include<bits/stdc++.h>
using namespace std;
int a[1000005],mas[50005],mae[50005];
signed main(){
	int n,maxx=-1;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		a[l]++;a[r+1]--;
	}
	int tmp=0;
	for(int i=1;i<=n;i++){
		tmp+=a[i];
		maxx=maxx<tmp?tmp:maxx;
	}
	printf("%d",maxx);
	int tim=1;
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
struct cow{int l,r;int rank;const bool operator<(const cow& c)const{return l<c.l;}}C[50005];
int ans,lan[50005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i){scanf("%d%d",&C[i].l,&C[i].r);C[i].rank=i;}sort(C,C+n);
	for(int i=0;i<n;++i){int t;
		if(!q.empty()&&q.top().first<C[i].l){t=q.top().second;q.pop();}
		else{ans++;t=ans;}
		q.push(make_pair(C[i].r,t));lan[C[i].rank]=t;}
	printf("%d\n",ans);
	for(int i=0;i<n;i++) printf("%d\n",lan[i]);
	return 0;}
