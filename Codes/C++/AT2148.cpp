#include<bits/stdc++.h>
#define pa pair<int,int>
#define maxn 100005
using namespace std;
priority_queue<pa>q;
vector<int>v[maxn];
int A,B,a[maxn];
bool used[maxn],has[maxn];
int main(){
	int n;scanf("%d",&n);for(int i=1;i<n;i++){
		scanf("%d%d",&A,&B);
		v[A].push_back(B);
		v[B].push_back(A);}
	int k;scanf("%d",&k);for(int i=0;i<k;i++){
		scanf("%d%d",&A,&B);
		a[A]=B;has[A]=1;q.push(pa(-B,A));}
	while(!q.empty()){
		B=-q.top().first,A=q.top().second;q.pop();
		used[A]=1;for(int i=0;i<(int)v[A].size();i++)
		if(!used[v[A][i]]&&has[v[A][i]]&&a[v[A][i]]!=B+1){puts("No");return 0;}
		else if(!used[v[A][i]]) used[v[A][i]]=1,a[v[A][i]]=B+1,q.push(pa(-B-1,v[A][i])),has[v[A][i]]=1;}
	puts("Yes");
	for(int i=1;i<=n;i++)printf("%d\n",a[i]);
	return 0;
}
