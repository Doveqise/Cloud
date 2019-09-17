#include<bits/stdc++.h>
using namespace std;
string a[205];
int tot;
int main(){
    char ch='0';
    int tot=0;
    cin>>a[0];
    for(int i=1;i<a[0].size();i++){
    	cin>>a[i];
	} 
    printf("%d ",a[0].size());
    for(int i=0;i<a[0].size();i++){
        for(int j=0;j<a[0].size();j++){
            if(a[i][j]==ch)tot++;
            else{
                ch=a[i][j];
                printf("%d ",tot);
                tot=1;
            }
        }
    }
    printf("%d",tot);
    return 0;
}
