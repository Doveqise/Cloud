#include<bits/stdc++.h>
using namespace std;
char word[105];
int main()
{
    cin>>word;
    int len=strlen(word);
    if (word[len-1]=='1'||word[len-1]=='3'||word[len-1]=='5'||word[len-1]=='7'||word[len-1]=='9')
        puts("contest");
    else
        puts("home");
    return 0;
}