#include<bits/stdc++.h>
using namespace std;
int flag=0;
inline long long read(){
    long long X=0,w=0,cnt=0,fl=0; char ch=getchar();
    if(flag)flag=0,w=1;ch=getchar();
    if(ch=='-'){ch=getchar();if(ch=='0'){fl=1;cnt++;}else if(isdigit(ch))X=ch^48,ch=getchar(),cnt++;else fl=1;}
    else if(ch=='0'){ch=getchar();if(isdigit(ch))fl=1;}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar(),cnt++;
    return (fl&&cnt)?(-19260817):(cnt>=20?(-192608170):(w?-X:X));
}
signed main(){
	long long l,r,T;scanf("%lld%lld%lld",&l,&r,&T);
	while(T--){
		long long num=read();
		if(num==-19260817){puts("1");continue;}
		if(num==-192608170){puts("2");continue;}
		if(num<=r&&num>=l){puts("0");continue;}
		puts("2");
	}
	return 0;
}
