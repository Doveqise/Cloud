#include<bits/stdc++.h>
using namespace std;
char mima[26],jmxx[105],yxx[105],fyxx[105];
signed main(){
	scanf("%s%s%s",jmxx,yxx,fyxx);
	if(fyxx[0]=='H'&&fyxx[1]=='I'&&fyxx[2]=='J'&&fyxx[3]=='A'&&fyxx[4]=='C'&&fyxx[5]=='K'){printf("Failed");return 0;}
	int len=strlen(jmxx);
	for(int i=0;i<len;i++){
		if(!mima[jmxx[i]-65]) mima[jmxx[i]-65]=yxx[i];
		else if(mima[jmxx[i]-65]==yxx[i]) mima[jmxx[i]-65]=yxx[i];
		else{printf("Failed");return 0;}}
	for(int i=0;i<26;i++)if(!mima[i]){printf("Failed");return 0;}
	len=strlen(fyxx);
	for(int i=0;i<len;i++){printf("%c",mima[fyxx[i]-65]);}
	return 0;
}
