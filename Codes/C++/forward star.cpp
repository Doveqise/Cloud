#include<bits/stdc++.h>
#define MAXM 10000
#define MAXN 10000
using namespace std;
struct edge{
	int next;
	int to;
	int weigh;
}e[MAXM];
int cnt,head[MAXN];
void add(int from,int to,int weigh){
	e[++cnt].next=head[from];
	e[cnt].weigh=weigh;
	e[cnt].to=to;
	head[from]=cnt;
}
void Print() {
	int st;
	cout << "Begin with[Please Input]: \n";
	cin >> st;
	for(int i=head[st]; i!=0; i=e[i].next) {//i��ʼΪ��һ���ߣ�ÿ��ָ����һ��(��0Ϊ������־)���±��0��ʼ��nextӦ��ʼ��-1 
		cout << "Start: " << st << endl;
		cout << "End: " << e[i].to << endl;
		cout << "W: " << e[i].weigh << endl << endl; 
	}
}
int main(){
	int n,m,s,t,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&s,&t,&w);
		add(s,t,w);
	}
}
