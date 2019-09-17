#include<bits/stdc++.h>
using namespace std;
int n,k;
char m[1000005];
int main(){
    scanf("%d%d%s",&n,&k,m);
    for(int i=0;i<n&&k!=0;i++)
    {	if(m[i]=='4'&&m[i+1]=='7'&&m[i+2]=='7'&&!(i%2)){
			k%=2;
		}
        if(k!=0&&m[i]=='4'&&m[i+1]=='7'){
            if(i%2) m[i]=m[i+1];
            else m[i+1]=m[i];
            i-=2;
            k--;
        }
    }   
    printf("%s",m);
    return 0;
}
