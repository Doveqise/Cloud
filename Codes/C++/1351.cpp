// #include<bits/stdc++.h>
// using namespace std;
// const int maxn = 2e6+5;
// const int MOD = 1e5+7;
// struct edge{int t,nxt;}E[maxn];
// int hd[maxn],cnt;
// void add(int a,int b){
// 	cnt++;
// 	E[cnt].t=b,E[cnt].nxt=hd[a];
// 	hd[a]=cnt;}
// long long wei[maxn],sum,maxx,tot,maxm;
// signed main(){
// 	int n;scanf("%d",&n);
// 	for(int i=1,a,b;i<n;i++){
// 		scanf("%d%d",&a,&b);
// 		add(a,b),add(b,a);}
// 	for(int i=1;i<=n;i++)scanf("%lld",&wei[i]);
// 	int t;for(int i=1;i<=n;i++){
// 		t=hd[i];
// 		tot=(maxm=wei[E[t].t])%MOD;
// 		t=E[t].nxt;
// 		while(t){
// 			sum=(sum+tot*wei[E[t].t])%MOD;
// 			maxx=max(maxx,maxm*wei[E[t].t]);
// 			tot=(tot+wei[E[t].t])%MOD;
// 			maxm=max(maxm,wei[E[t].t]);
// 			t=E[t].nxt;
// 		}
// 	}
// 	printf("%lld %lld\n",maxx,(sum*2)%MOD);
// 	return 0;
// }
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct Edge
{
    int t,nexty;
    Edge(){t=nexty=0;}
}edge[1000000];//链式前向星邻接表
int head[300000]={0},cnt=0;//链式前向星链表变量
void add(int a,int b)//加边
{
    cnt++;
    edge[cnt].t=b,edge[cnt].nexty=head[a];
    head[a]=cnt;//加边过程（如果不懂链式前向星，可以百度一下）
}
long long w[300000]={0};//每个点的权值
int main()
{
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);//加边
    }
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);//读入权值
    long long sum=0,maxn=0;//全局的和，最大值
    long long he,rmax;//一段的和与一段的最大值
    int node;
    for(int i=1;i<=n;i++)
    {
        node=head[i];//第一个元素
        he=(rmax=w[edge[node].t])%10007;//得到初始值
        node=edge[node].nexty;//下一个
        for(;node!=0;node=edge[node].nexty)//枚举与之相连的点
        {
            sum=(sum+he*w[edge[node].t])%10007;//乘法结合律
            maxn=max(maxn,rmax*w[edge[node].t]);//贪心，取最大值
            he=(he+w[edge[node].t])%10007;
            rmax=max(rmax,w[edge[node].t]);//更新
        }
    }
    printf("%lld %lld",maxn,(sum*2)%10007);//记得*2
    return 0;
}