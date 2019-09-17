#include<bits/stdc++.h>
using namespace std;
int a[1005];
signed main(){
  int n;scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  sort(a+1,a+1+n);
  int l=1,r=n; 
  while(l<r&&a[l]&&a[r]){
    printf("%d %d ",a[l++],a[r--]);
  }
  if(l==r)printf("%d ",a[l]);
  return 0;
}