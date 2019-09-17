#include<bits/stdc++.h>
using namespace std;
string a;
int ans=0,len;
int main(){
	getline(cin,a);
	len=a.length();
	for(int i=0;i<len;i++){
		if(a[i]=='a'||a[i]=='d'||a[i]=='g'||a[i]=='j'||a[i]=='m'||a[i]=='p'||a[i]=='t'||a[i]=='w'||a[i]==' ')ans++;
		else if(a[i]=='b'||a[i]=='e'||a[i]=='h'||a[i]=='k'||a[i]=='n'||a[i]=='q'||a[i]=='u'||a[i]=='x')ans+=2;
		else if(a[i]=='c'||a[i]=='f'||a[i]=='i'||a[i]=='l'||a[i]=='o'||a[i]=='r'||a[i]=='v'||a[i]=='y')ans+=3;
		else if(a[i]=='s'||a[i]=='z')ans+=4;
	}
	printf("%d",ans);
	return 0;
}
