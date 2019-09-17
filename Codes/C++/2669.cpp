#include<bits/stdc++.h>
using namespace std;
int num[3],p[3];
int main(){
	int n,min=INT_MAX;
	scanf("%d",&n);
	scanf("%d%d%d%d%d%d",num,p,num+1,p+1,num+2,p+2);
	for(int i=0;i<3;i++){
		if(n%num[i]) num[i]=n/num[i]+1;
		else num[i]=n/num[i];
		p[i]*=num[i];
		if(p[i]<min) min=p[i];
	}
	printf("%d",min);
	return 0;
}
