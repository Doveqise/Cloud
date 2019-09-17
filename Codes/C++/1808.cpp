#include<bits/stdc++.h>
using namespace std;
struct sword{char w[26];}s[10005];
char word[105];
int ans;
bool cmp(sword a,sword b){for(int i=0;i<26;i++) if(a.w[i]!=b.w[i])return a.w[i]<b.w[i];}
signed main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",word);
		int len=strlen(word);
		for(int j=0;j<len;j++) s[i].w[word[j]-65]++;
	}
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++) for(int j=0;j<26;j++) if(s[i].w[j]!=s[i+1].w[j]){ans++;break;}
	printf("%d",ans);
	return 0;
} 
