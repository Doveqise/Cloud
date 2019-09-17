#include<bits/stdc++.h>
using namespace std;
map<string,string>fa;
string findfa(string s){return fa[s]==s?s:findfa(fa[s]);}
signed main(){
	string son,father;char op;cin>>op;
	while(op!='$'){
		cin>>son;if(op=='#'){father=son;if(fa[son]=="")fa[son]=son;}
		else if(op=='+')fa[son]=father;
		else if(op=='?') cout<<son<<' '<<findfa(son)<<endl;cin>>op;}
	return 0;
}

