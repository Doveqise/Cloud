#include<bits/stdc++.h>
using namespace std;
string s;
int word[26];
signed main()
{
    cin>>s;
    int k,cnt=0;
    scanf("%d",&k);
    if(k>s.length()||k>26)
        puts("impossible");
    else
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<'a'||s[i]>'z')
                continue;
            if(!word[s[i]-'a'])
            {
                word[s[i]-'a']=1;
                cnt++;
            }
        }
        printf("%d\n",k<cnt?0:k-cnt);
    }
    return 0;
}