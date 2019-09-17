#include<bits/stdc++.h>
using namespace std;
const int sdt[5][5]={{2,2,2,2,2},{1,2,2,2,2},{1,1,0,2,2},{1,1,1,1,2},{1,1,1,1,1}};
const int dx[]={-2,-1,1,2,2,1,-1,-2};
const int dy[]={1,2,2,1,-1,-2,-2,-1};
int T,ans=16,mx,b=1;
int mp[7][7],mp2[7][7];
inline int cntt(){int cnt=0;
    for(int i=1;i<=5;i++) for(int j=1;j<=5;j++)
    if(mp[i][j]!=sdt[i-1][j-1])cnt++;
    return cnt;}
inline bool jud(int x,int y){return (x>=1&&x<=5&&y>=1&&y<=5)?1:0;}
void dfs(int x,int cx,int cy){
    if(x>mx)return;int bs=cntt();
    if(!bs){ans=min(ans,x);b=0;return;}
    if(!b||bs+x-1>mx)return;
    for(int i=0,a1,b1;i<=7;i++){
        a1=cx+dx[i],b1=cy+dy[i];
        if(jud(a1,b1)){
            swap(mp[a1][b1],mp[cx][cy]);
            dfs(x+1,a1,b1);
            swap(mp[a1][b1],mp[cx][cy]);}
    }
}
int main(){
    scanf("%d",&T);while(T--){
        memset(mp,-1,sizeof(mp));b=1,ans=16;        
        for(int i=1;i<=5;i++){
            char ch[10];scanf("%s",ch);
            for(int j=1;j<=5;j++){
                if(ch[j-1]=='*')mp2[i][j]=0;
                else mp2[i][j]=(ch[j-1]-'0'+1);}
        }
        int a,b;for(int i=1;i<=5;i++) for(int j=1;j<=5;j++)
        	if(!mp2[i][j]){a=i,b=j;break;}
        for(mx=1;mx<=15;mx++){
            for(int i=1;i<=5;i++) for(int j=1;j<=5;j++) mp[i][j]=mp2[i][j];
            dfs(0,a,b);if(ans==mx||!b)break;}
        if(ans==16) printf("-1\n");
        else printf("%d\n",ans);  
    }
    return 0;
}