#include<cstdio>
using namespace std;
int ys[42];
int main(){
	int t,ans=0;
	for(int i=0;i<10;i++){
		scanf("%d",&t);
		ys[t%42]++;
	}
	for(int i=0;i<42;i++) if(ys[i]) ans++;
	printf("%d",ans);
	return 0;
}
