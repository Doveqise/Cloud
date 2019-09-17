#include<bits/stdc++.h>
using namespace std;
struct man{
	char num[105];
	int numb,ws;
}m[25];
bool cmp(man a,man b){if(a.ws!=b.ws) return a.ws>b.ws;else for(int i=0;i<105;i++) if(a.num[i]!=b.num[i]) return a.num[i]>b.num[i];}
signed main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){m[i].numb=i;scanf("%s",m[i].num);m[i].ws=strlen(m[i].num);}
	sort(m,m+n,cmp);
	printf("%d\n%s",m[0].numb+1,m[0].num);
	return 0;
}
