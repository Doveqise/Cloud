#include<bits/stdc++.h>
typedef unsigned long long ull;  
using namespace std;
ull base=137;
ull a[10010];
char s[10010];
int n,ans=1,prime=1e9+7;
ull mod=21237044013013795711;
ull hash(char s[]){
	int leng=strlen(s);
	ull ans=0;
	for(int i=0;i<leng;i++) ans=(ans*prime+(ull)s[i])%mod+prime;
	return ans;
}
signed main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		a[i]=hash(s);
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
		if(a[i]!=a[i+1]) ans++;
	printf("%d",ans);
	return 0;
} 
