#include<bits/stdc++.h>
using namespace std;
string s;map<char,bool> p;
int main(){
    cin>>s;int sum=0;int lim=s.length();
    p['A']=1,p['E']=1,p['F']=1,p['H']=1,p['I']=1,p['K']=1,p['L']=1,p['M']=1,p['N']=1,p['T']=1,p['V']=1,p['W']=1,p['X']=1,p['Y']=1,p['Z']=1;
    for(int i=0;i<lim;i++) sum+=p[s[i]];
    if(sum==lim||(!sum)) puts("YES");
    else puts("NO");
    return 0;
}