#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]=='C'){
			for(int j=len-1;j>i;j--){
				if(s[j]=='F'){
					printf("Yes");
					return 0;}}}}
	printf("No");return 0;}
