#include<bits/stdc++.h>
using namespace std;
int a[10]={0,1,0,0,0,0,0,1,0,1};
int main(){
    int n;scanf("%d",&n);
    puts(((a[n%10]||(n>9&&n<30)||a[n/10])&&n!=12)?"NO":"YES");
    return 0;
}