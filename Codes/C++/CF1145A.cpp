#include<bits/stdc++.h>
using namespace std;
int a[16],ans=1;
bool pd(int l,int r){
  for(int i=l;i<r;i++) if(a[i]>a[i+1]) return 0;
  return 1;}
void solve(int l,int r){
  if(l>=r)return;
  if(pd(l,r))ans=max(ans,r-l+1);
  int mid=(l+r)>>1;
  solve(l,mid);solve(mid+1,r);
}
signed main(){
  int n;scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  solve(1,n);printf("%d",ans);
  return 0;
}