#include<bits/stdc++.h>
const int MOD = 19260817;
inline int read(){
    int res=0,ch=getchar();
    while(!isdigit(ch)&&ch!=EOF)ch = getchar();
    while(isdigit(ch)){res =(res*10+ch-'0')%MOD;ch = getchar();}
    return res;}
int x,y;
void exgcd(int a, int b){
    if(b == 0){x = 1;y = 0;return;}
    exgcd(b, a % b);
    int Last_x=x;
    x=y;
    y=Last_x-a/b*y;
}
int main(){
    int a, b;a=read();b=read();
    if(!b)puts("Angry!");
    else{
	exgcd(b,MOD);
    x=(x%MOD+MOD)%MOD;
    printf("%lld\n",a*(long long)(x)%MOD);
    }
    return 0;
}
