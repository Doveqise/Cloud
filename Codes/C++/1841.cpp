#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7,N=200+5;
int e[N][N],city[N][N],m,n;
bool ans[N],flag;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) e[i][j]=INF;//�޷�����
    for(int i=1;i<=m;i++){int x,y,u;scanf("%d%d%d",&x,&y,&u);e[x][y]=e[y][x]=u;}//����
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++)
		if(i!=k) for(int j=1;j<=n;j++) if(i!=j&&j!=k){//�ж�
			if(e[i][j]>e[i][k]+e[k][j]){e[i][j]=e[i][k]+e[k][j];city[i][j]=k;}//������ʽ
			else if(e[i][j]==e[i][k]+e[k][j]) city[i][j]=-1;//��Ҫ����
		}
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(city[i][j]!=-1) ans[city[i][j]]=true;    
    for(int i=1;i<=n;i++) if(ans[i]){printf("%d ",i);flag=true;}
    if(!flag) puts("No important cities.");
    return 0;
}
