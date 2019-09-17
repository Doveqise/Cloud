#include<bits/stdc++.h>
using namespace std;
struct man{
	string s;
	int y;
	int m;
	int d;
	int cixu;
}m[105];
bool cmp(man a,man b){
	if(a.y>b.y) return false;
	else if(a.y==b.y&&a.m>b.m) return false;
	else if(a.y==b.y&&a.m==b.m&&a.d>b.d) return false;
	else if(a.y==b.y&&a.m==b.m&&a.d==b.d) return a.cixu>b.cixu; 
	else return true;
}
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){cin>>m[i].s>>m[i].y>>m[i].m>>m[i].d;m[i].cixu=i+1;}
	sort(m,m+n,cmp);
	for(int i=0;i<n;i++)cout<<m[i].s<<endl;
	return 0;
}
