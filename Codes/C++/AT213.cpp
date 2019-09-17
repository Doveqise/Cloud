#include<bits/stdc++.h>
using namespace std;
int h,w,a,b,v[505][505];
int dy[4]={0,0,1,-1},dx[4]={1,-1,0,0};
bool flag;
char m[505][505];
void dfs(int y,int x,int f){
	if(y<0||y>=h||x<0||x>=w||(v[y][x]&&f>=v[y][x]))return;
	if(m[y][x]=='g'){flag=1;return;}
	if(m[y][x]=='#'){if(f==3)return;f++;}
	v[y][x]=f;
	for(int i=0;i<4;i++)
		dfs(y+dy[i],x+dx[i],f);
}
int main(){
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++){
		scanf("\n");
		for(int j=0;j<w;j++){
			scanf("%c",&m[i][j]);
			if(m[i][j]=='s')a=i,b=j;
		}
	}
	dfs(a,b,1);
	flag?puts("YES"):puts("NO");
}
