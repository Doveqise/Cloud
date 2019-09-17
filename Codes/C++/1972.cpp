#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define N 2110000
using namespace std;
int ans,cnt[N],l=0,r=0,answer[N];
int a[N];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;}
inline void putoutt(int x){
    if(x<0){putchar('-');putoutt(-x);return;}
    if(x>=10)putoutt(x/10);
    putchar(x%10+'0');}
inline void putout(int x){putoutt(x);putchar('\n');}
struct que{int left,right,k;}Q[N];
int cmp(const que &x,const que &y){
    if(x.left==y.left)return x.right<y.right;
    else return x.left<y.left;}    
void Add(int u){cnt[u]++;if(cnt[u]==1)ans++;}                     
void Move(int v){cnt[v]--;if(!cnt[v])ans--;}
int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    int m=read();
    for(int i=1;i<=m;i++){Q[i].left=read(),Q[i].right=read();Q[i].k=i;}
    sort(Q+1,Q+m+1,cmp);        
    for(int i=1;i<=m;i++){
        while(r<Q[i].right)r++,Add(a[r]);
        while(r>Q[i].right)Move(a[r]),r--;
        while(l<Q[i].left)Move(a[l]),l++;
        while(l>Q[i].left)l--,Add(a[l]);
        answer[Q[i].k]=ans;}
    for(int i=1;i<=m;i++) putout(answer[i]);
    return 0;
}
