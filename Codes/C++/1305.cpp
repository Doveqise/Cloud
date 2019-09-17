/*#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num;
    char data;
    node * l;
    node * r;
};
node t[10001];
int n;
int top;
map<char,int>ap;
void qx(int i)
{
    printf("%c",t[i].data);
    if(t[i].l!= nullptr)
    qx(t[i].l->num);
    if(t[i].r!= nullptr) 
    qx(t[i].r->num);
}
int main(){
	scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char a,b,c;
        scanf("%c%c%c",&a,&b,&c);
        if(ap.count(a)==0)
        {
            ++top;
            ap[a]=top;
        }
        if(ap.count(b)==0&&b!='*')
        {
            ++top;
            ap[b]=top;
            t[ap[b]].num=ap[b];
        }
        if(!ap.count(c)&&c!='*')
        {    ++top; 
            ap[c]=top;
            t[ap[c]].num=ap[c];
        } 
        t[ap[a]].data=a;
        t[ap[a]].num=ap[a];
        if(b!='*')
        t[ap[a]].l=&t[ap[b]];
        else t[ap[a]].l=nullptr;
        if(c!='*')
        t[ap[a]].r=&t[ap[c]];
        else t[ap[a]].r=nullptr;
    }
    qx(1);
}
*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int n;
string s;
int main()
{
    cin>>n>>s;
    for(int i=2;i<=n;++i)
    {
        string ss;
        cin>>ss;
        int x=s.find(ss[0]);
        s.erase(x,1);
        s.insert(x,ss);
    }
    for(int i=0;i<s.size();++i) if(s[i]!='*') cout<<s[i];
    return 0; 
}
