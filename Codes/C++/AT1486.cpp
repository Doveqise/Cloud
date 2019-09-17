#include<bits/stdc++.h>
using namespace std;
signed main(){
	char ch,date1,date2;
	int num;
	scanf("%c%c%c%d",&date1,&date2,&ch,&num);
	if(ch=='B')printf("Bachelor ");
	if(ch=='M')printf("Master ");
	if(ch=='D')printf("Doctor ");
	printf("%c%c\n",date1,date2);
	return 0;
}