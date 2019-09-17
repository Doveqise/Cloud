/*#include<bits/stdc++.h>
using namespace std;
string str[7],re[7];
int st[30],flag;
bool cmp(string a,string b){
	return a+b<b+a;
}
int turn(string stri){
	if(stri=="one")return 1;
	if(stri=="two")return 2;
	if(stri=="three")return 3;
	if(stri=="four")return 4;
	if(stri=="five")return 5;
	if(stri=="six")return 6;
	if(stri=="seven")return 7;
	if(stri=="eight")return 8;
	if(stri=="nine")return 9;
	if(stri=="ten")return 10;
	if(stri=="eleven")return 11;
	if(stri=="twelve")return 12;
	if(stri=="thirteen")return 13;
	if(stri=="fourteen")return 14;
	if(stri=="fifteen")return 15;
	if(stri=="sixteen")return 16;
	if(stri=="seventeen")return 17;
	if(stri=="eighteen")return 18;
	if(stri=="nineteen")return 19;
	if(stri=="twenty")return 20;
	else return 0;
}
signed main(){
	for(int i=1;i<=6;i++){
		cin>>str[i];
		if(turn(str[i])!=-1){
			st[i]=(int)pow(turn(str[i]),2)%100;
			re[i][0]=st[i]/10+30;
			re[i][1]=st[i]%10+30;
		}
	}
	sort(re+1,re+7,cmp);
	for(int i=1;i<=6;i++){
		for(int j=0;j<2;j++){
			if(re[i][j]!='0'&&(!flag)){
				flag=1;
			}
			if(re[i][j]!='0'||flag){
				printf("%c",str[i][j]);
			}
		}
	}
	return 0;
} */
#include<bits/stdc++.h>
using namespace std;
char dic[30][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};//∂‘”¶
int di[30]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
unsigned long long int a[10],top,flag;
int i,j;
char s[100];
int main()
{
     for(i=1;i<=6;i++)
     {
          scanf("%s",&s);
          for(j=1;j<=26;j++)
          {
               if(!strcmp(s,dic[j]))
               {
                    a[++top]=di[j];
                    break;
               }
          }
      }
      sort(a+1,a+top+1);
      for(i=1;i<=top;i++)
      {
           if(flag)
           {
                printf("%.2d",a[i]);
           }
           else
           {
                if(a[i])
                { 
                     printf("%d",a[i]);
                     flag=1;
                }
            }
     }
     if(!flag)printf("0");
     return 0;
}
