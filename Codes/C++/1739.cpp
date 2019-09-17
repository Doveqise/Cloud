#include<cstdio>
using namespace std;
char str[300];
int main(){
	int num=0,i=0;
	scanf("%s",str);
	while(str[i]!='@'){
		if(str[i]=='(') num++;
		if(str[i]==')') {
			if(num) num--;
			else{
				printf("NO");
				return 0;
			}
		}
		i++;
	}
	if(num){
		printf("NO");
		return 0;
	}
	printf("YES");
	return 0;
} 
