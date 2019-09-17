#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct Point{
int l,f;
}p[1000005];
bool cmp(Point a, Point b){return a.l<b.l;}
int main(){
    int f=1;
    int n,L,P;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&p[i].l,&p[i].f);
    scanf("%d%d",&L,&P);
    for(int i=0;i<n;i++)
        p[i].l=L-p[i].l; 
    	p[n].f=0;
    	p[n].l=L;
    	n++; 
    sort(p,p+n,cmp);
    priority_queue <int> q;
    int ans=0,pos=0,num=P;
    for(int i=0;i<n;i++){
        int dis=p[i].l-pos;
        while(num<dis)
        {
            if(q.empty()){printf("-1");f=0;return 0;}
            ans++;
            num+=q.top();
            q.pop();
        }
        if(!f) break;
        num-=dis;   
        q.push(p[i].f);
        pos=p[i].l;
    }
     printf("%d",ans);
   }
