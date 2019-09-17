#include<bits/stdc++.h>
using namespace std;
int q[200005],a[200005];
int main(){
	int m,d;scanf("%d%d",&m,&d);
	int t=0,add,tail=0,l=0;
	while(m--){
		char ch;int x;cin>>ch>>x;
		if(ch=='A'){
			add=(t+x)%d;
			while(add>=q[tail]&&tail)--tail;
			q[++tail]=add;
			a[tail]=++l;
		}else{
			t=q[lower_bound(a+1,a+1+tail,l-x+1)-a];
			printf("%d\n",t);
		}
	}
	return 0;
}
