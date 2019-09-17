/*#include<bits/stdc++.h>
using namespace std;
int xy[10]={6,2,5,5,4,5,6,3,7,6};
int ans=0;
void sc(int a,int b,int c){
	if(a<b)swap(a,b);
	if(b<10){
		if(a<10){
			if(a+b<10){
				if(xy[a]+xy[b]+xy[a+b]==c-4){
					ans++;
				}
			}
			else if(xy[a]+xy[b]+xy[a+b-10]+2==c-4){
				ans++;
			}
			return;
		}
		if(a>=10){
			if(xy[a%10]+xy[b]+xy[(a+b)%10]+xy[(a-a%10)/10]+xy[(a+b-(a+b)%10)/10]==c-4){
				ans++;
			}
			return;
		}
	}
	if(xy[a%10]+xy[b%10]+xy[(a+b)%10]+xy[(a-a%10)/10]+xy[(b-b%10)/10]+xy[(a+b-(a+b)%10)/10]==c-4){
		ans++;
	}
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=999;i++){
		for(int j=0;j<=999;j++){
			sc(i,j,n);
		}
	}
	printf("%d",ans);
	return 0;
}*/
#include<bits/stdc++.h>
int main(){
        int num[5001]={6},hi[10]={6,2,5,5,4,5,6,3,7,6};
		int n,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=5000;i++){
                int j=i;
                while(j>=1){
					num[i]+=hi[j%10];
            		j/=10;
                }
                j=0;
        }
        for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++) if(num[i]+num[j]+num[i+j]+4==n) ans++;
        printf("%d",ans);
        return 0;
}
/*
思维：将0~1111所用火柴棒个数先求出来，后调用
*/ 
