#include<bits/stdc++.h>
using namespace std;
int main() {
    int x,y;scanf("%d%d",&x,&y);
    x--;y--;
    string w;cin>>w;
    char m[9][9];
    for(int i=0;i<9;i++){
		scanf("\n");
		for(int j=0;j<9;j++) scanf("%c",&m[i][j]);
	}
    int dy[8]={0,0,-1,-1,1,1,-1,1};
    int dx[8]={1,-1,1,0,0,-1,-1,1};
    string s[8]={"R","L","RU","U","D","LD","LU","RD"};
    printf("%c",m[y][x]);
    int ddy=1,ddx=1;
    for(int i=0;i<8;i++)
		if(w==s[i])ddy=dy[i],ddx=dx[i];
    for(int i=0;i<3;i++){
        if(x+ddx<0||x+ddx>=9)ddx=-ddx;
        if(y+ddy<0||y+ddy>=9)ddy=-ddy;
        x+=ddx;y+=ddy;
        printf("%c",m[y][x]);
    }
    puts("");
    return 0;
}
