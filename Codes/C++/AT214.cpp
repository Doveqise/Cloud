#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int num[20],len,f[15][15][95][20],ava[10],anslen=inf,anscnt;
char s[10];
long long price,pw[20],ansnum[15];
int dfs1(int cnt,int dn,int sum,int ps){
	if(~f[cnt][dn][sum][ps])return f[cnt][dn][sum][ps];
	if(ps>=len)return f[cnt][dn][sum][ps]=(sum==0?0:inf);
	if(dn>=cnt)return f[cnt][dn][sum][ps]=(num[ps]==sum%10?dfs1(cnt,0,sum/10,ps+1):inf);
	int res=inf;
	for(int i=0;i<=9;i++)if(ava[i])res=min(res,dfs1(cnt,dn+1,sum+i,ps)+1);
	if(dn)res=min(res,dfs1(dn,dn,sum,ps));
	return f[cnt][dn][sum][ps]=res;
}
void dfs2(int cnt,int dn,int sum,int ps){
	if(ps>=len)return;
	if(dn>=cnt){dfs2(cnt,0,sum/10,ps+1);return;}
	int now=f[cnt][dn][sum][ps];
	for(int i=0;i<=9;i++)if(ava[i]&&f[cnt][dn+1][sum+i][ps]+1==now){
		ansnum[dn]+=1ll*i*pw[ps],dfs2(cnt,dn+1,sum+i,ps);return;}
	dfs2(dn,dn,sum,ps);
}
int main(){
	scanf("%s%lld",s,&price);
	int leng=strlen(s);
	for(int i=0;i<=leng;i++)ava[s[i]-'0']=1;
	while(price)num[len++]=price%10,price/=10;
	memset(f,-1,sizeof(f));
	for(int i=1;i<=10;i++){
		int now=(i==1?0:i)+dfs1(i,0,0,0);
		if(now<anslen)anslen=now,anscnt=i;
	}
	pw[0]=1;
	for(int i=1;i<=len;i++)pw[i]=pw[i-1]*10;
	dfs2(anscnt,0,0,0);if(anscnt==1)printf("%lld",ansnum[0]);
	else for(int i=0;i<=anscnt-1;i++){printf("%lld",ansnum[i]);printf("%c",(i+1)==anscnt?'=':'+');}
	puts("");return 0;
}
