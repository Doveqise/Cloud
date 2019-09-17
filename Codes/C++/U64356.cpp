#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n;scanf("%d\n",&n);
	while(n--){
		int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x+=ch-'0';ch=getchar();}
		if(x%3)puts("1");
		else puts("0");}
	return 0;
}
