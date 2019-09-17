#include<bits/stdc++.h>
#include<stack>
#define MAXN 10005
#define MAXM 100005
using namespace std;
int DFN[MAXN],low[MAXN],colour[MAXN],In_stack[MAXN],wei[MAXN];
int Index,len,u,v,color=1,weigh,maxx;
stack<int>Stack;
struct edge{
	int st;
	int en;
	int we;
}ed[MAXM<<1];
void add(int x,int y){
	ed[++m].st=x;
	ed[m].en=y;
}
void tarjan(int u){
	if(DFN[u]) return;
	DFN[u]=low[u]=++Index;
	Stack.push(u);
	In_stack[u]=1;
	for(int i=1;i<=len;i++) if(ed[i].st==u){v=ed[i].en;
		if(!DFN[v]){tarjan(v);low[u]=min(low[u],low[v]);}
		else if(In_stack[v])low[u]=min(low[u],DFN[v]);
		}
	if(DFN[u]==low[u])
		{	do{	v=Stack.top();
			Stack.pop();
			printf("%d ",v);
			colour[v]=color;
			In_stack[v]=0;
			}while(DFN[u]!=DFN[v]);
			++color;
		}
}
signed main(){
	int n,m;scanf("%d%d",&n,&m);len=m;
	for(int i=1;i<=n;i++) scanf("%d",&wei[i]);
	for(int i=1;i<=m;i++) scanf("%d%d",&ed[i].st,&ed[i].en);
	for(int i=1;i<=n;i++) tarjan(i);
	for(int i=1;i<=color;i++){
		weigh=0;
		for(int j=1;j<=n;j++) if(colour[j]==i) {
			weigh+=wei[j];printf("%d ",j);
		}
		maxx=max(maxx,weigh);
	}
	printf("%d ",maxx);
	return 0;
}

#include<cstdio>
#include<algorithm>
#include<cstdlib>
int first[100050],next[100050],to[100050],DFN[100050],low[100050],tot=0,inX=0,IN[100050],stack[100050],bot=1,top=1,COM[100050],COL=0,point[100050],tot1=0,next1[100050],to1[100050],first1[100050],weight[100050],TON[100050],QUE[100050],head=1,tail=1,BIGG[100050],MAXS=0;
int add(int x,int y)
{
	next[++tot]=first[x];
	to[tot]=y;
	first[x]=tot;
	return 0;
}
int add1(int x,int y)
{
	next1[++tot1]=first1[x];
	to1[tot1]=y;
	first1[x]=tot1;
	return 0;
}
int tarjan(int a)
{
	int T;
	if(DFN[a])
	{
		return 0;
	}
	DFN[a]=++inX;
	low[a]=DFN[a];
	T=first[a];
	stack[top++]=a;
	IN[a]=1;
	while(T)
	{
		if(!DFN[to[T]])
		{
			tarjan(to[T]);
			low[a]=std::min(low[a],low[to[T]]);
		}
		else
		{
			if(IN[to[T]])
			{
				low[a]=std::min(low[a],low[to[T]]);
			}
		}
		T=next[T];
	}
	if(DFN[a]==low[a])
	{
		COL++;
		//printf("COL=%d\n",COL);
		do
		{
			top--;
			COM[stack[top]]=COL;
			point[COL]+=weight[stack[top]];
			IN[stack[top]]=0;
		}while(DFN[a]!=DFN[stack[top]]&&top!=bot);
	}
	return 0;
}
int gather(int a)
{
	int i,T;
	for(i=1;i<=a;i++)
	{
		T=first[i];
		while(T)
		{
			if(COM[i]!=COM[to[T]])
			{
				add1(COM[i],COM[to[T]]);
				TON[COM[to[T]]]++;
			}
			T=next[T];
		}
	}
	for(i=1;i<=COL;i++)
	{
		BIGG[i]=point[i];
		if(BIGG[i]>=MAXS)
		{
			MAXS=BIGG[i];
		}
		if(!TON[i])
		{
			QUE[head++]=i;
		}
	}
	return 0;
}
int TOPO()
{
	int T;
	while(head!=tail)
	{
		T=first1[QUE[tail]];
		while(T)
		{
			BIGG[to1[T]]=std::max(BIGG[to1[T]],BIGG[QUE[tail]]+point[to1[T]]);
			//printf("BIGG[%d]=%d\n",to1[T],BIGG[to1[T]]);
			if(BIGG[to1[T]]>=MAXS)
			{
				MAXS=BIGG[to1[T]];
			}
			TON[to1[T]]--;
			if(!TON[to1[T]])
			{
				QUE[head++]=to1[T];
			}
			T=next1[T];
		}
		tail++;
	}
	return 0;
}
int main()
{
	int a,b,i,x,y,T;
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;i++)
	{
		scanf("%d",&weight[i]);
	}
	for(i=1;i<=b;i++)
	{
		scanf("%d%d",&x,&y);
		if(x==y)
		{
			continue;
		}
		add(y,x);
	}
	for(i=1;i<=a;i++)
	{
		tarjan(i);
	}
	gather(a);
	TOPO();
	printf("%d ",MAXS);
	return 0;
}

