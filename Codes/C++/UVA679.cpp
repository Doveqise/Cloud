#include<bits/stdc++.h>
int o[1000000];
int main(){
	scanf("%d",&o[999999]);
	while(o[999999]--){
		scanf("%d",&o[999998]);
		if(o[999998]+1){
			scanf("%d",&o[999997]);
			o[999998]=pow(2,o[999998]-1);
			while(o[999997]--){
				o[0]=1;
				while(o[0]<o[999998])o[o[0]]?((o[o[0]]=0,o[0]=o[0]<<1,o[0]++)):((o[o[0]]=1,o[0]=o[0]<<1));
			}
			printf("%d\n",o[0]);
			memset(o,0,o[999998]*4);
		}
		else return 0;
	}
}
/*#include<bits/stdc++.h>
signed main(){
	int n[5];
	scanf("%d",&n[0]);
using namespace std;
	while(n[0]--){
		n[3]=1;
		scanf("%d%d",&n[1],&n[2]);
		while(n[1]--){
			if(n[2]%2){n[2]=(n[2]+1)/2;n[3]*=2;}
			else{n[2]/=2;n[3]=n[3]*2+1;}
		}printf("%d\n",n[3]/2);
	}
}*/
