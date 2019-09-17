#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int Z=10;
int T,n,tot;
int ch[N][Z];
bool bo[N];
char s[20];
bool insert(char *s)
{
    int len=strlen(s);
    int u=1;
    bool flag=false;
    for(int i=0;i<len;i++)
        {
            int c=s[i]-'0';
            if(!ch[u][c])
                ch[u][c]=++tot;
            else if(i==len-1)
                flag=1;
            u=ch[u][c];
            if(bo[u])
                flag=1;
        }
    bo[u]=1;
    return flag;
}
signed main()
{

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        tot=1;
        memset(ch,0,sizeof(ch));
        memset(bo,0,sizeof(bo));
        bool ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            if(insert(s))
                ans=1;

        }
        if(!ans)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}