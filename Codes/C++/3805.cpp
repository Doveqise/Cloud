#include<bits/stdc++.h>
#define N 320007
using namespace std;
int tot,len,mr,pos,ml,p[N];
char ch[N],s[N];
int main () {
    s[0]='$';
        len=strlen(ch);tot=0;
        for (int i=0;i<len;i++)
         s[++tot]='#',s[++tot]=ch[i];
        s[++tot]='#'; s[++tot]=21;
         mr=pos=ml=0;
        for (int i=1;i<tot;i++) {
            if (i<mr) p[i]=min(p[pos*2-i],mr-i);
            else p[i]=1;
            while (s[i+p[i]]==s[i-p[i]]) p[i]++;
            if (i+p[i]>mr)  mr=i+p[i],pos=i;
            ml=max(ml,p[i]-1);
        }
        printf("%d\n",ml);
}
