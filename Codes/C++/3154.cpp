#include<bits/stdc++.h>
#define ri register long long
const int mod=1e9+7;
using namespace std;
long long n;
long long s[15];
map<long long,long long>mmp;
bool cmp(ri a,ri b){return a>b;}
long long has(int a){
	long long tmp=a;
	long long tp[15];
	for(ri i=1;i<=a;i++) tp[i]=s[i];
	sort(tp+1,tp+a+1,cmp);
	for(int i=1;i<=a;i++) tmp+=tmp*28+tp[i];
	return tmp;
}
long long dfs(ri a,ri b){
	if(s[b]+3*a>3*b)return -1;
	ri ret=0;
	if(a==b){
		if(b==1)return 1;
		else {
			ri ha=has(b-1);
			if(mmp[ha])return mmp[ha];
			return mmp[ha]=dfs(1,b-1);
		}
	}
	if(s[b]>=3){
		ri tmp=0;
		s[b]-=3;
		tmp=dfs(a+1,b);
		if(tmp!=-1){ret+=tmp;ret%=mod;}
		s[b]+=3;
	}
	if(s[a]&&s[b]){
		ri tmp=0;
		s[a]--;s[b]--;
		tmp=dfs(a+1,b);
		if(tmp!=-1){ret+=tmp;ret%=mod;}
		s[a]++;s[b]++;
	}
	if(s[a]>=3){
		ri tmp=0;
		s[a]-=3;
		tmp=dfs(a+1,b);
		if(tmp!=-1){ret+=tmp;ret%=mod;}
		s[a]+=3;
	}
	return ret?ret:-1;
}
int main(){
    scanf("%lld",&n);
    for(ri i=1;i<=n;i++)scanf("%lld",&s[i]);
    sort(s+1,s+n+1,cmp);
    printf("%lld\n",dfs(1,n));
    return 0;
}
