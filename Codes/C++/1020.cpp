#include<cstdio>
using namespace std;
int dd[100000];
int main(){
	int h;
	while(!scanf("%d",&h)){
		int i=0;
		while(dd[i]!=0){
			if(dd[i]>=h){
				dd[i]=h;
				h=0;
				i=99999;
			}
			i++;
		};
		if(h!=0) dd[i]=h;
		h=0;
	}
	for(int i=0;i<=100000;i++){
		if(!dd[i]){
			printf("%d",i);
			return 0;
		}
	}
}
