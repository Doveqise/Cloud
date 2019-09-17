#include<bits/stdc++.h>
using namespace std;
const int Maxn = 1000050;
namespace segtree
{
    struct node
    {
        int l,r,s,laz;
        node *ch[2];
    }
    pool[Maxn],*root;
    void build(node *n,int le,int ri)
    {
        n->l=le;
        n->r=ri;
        if(le==ri)
        {
            n->s=n[le];
            return;
        }
        int mid=(le+ri)>>1;
        node *ls=&pool[++cnt];
        node *rs=&pool[++cnt];
        n->ch[0]=ls;
        n->ch[1]=rs;
        build(ls,le,mid);
        build(rs,mid+1,ri);
        n->s=n->ch[0]->s+n->ch[1]->s;
    }
    void pushdown(node *n)
    {
        if(!n->laz)return;
        n->s+=(n->r-n->l+1)*n->laz;
        if(n->ch[0]) 
            n->ch[0]->laz+=n->laz;
        if(n->ch[1]) 
            n->ch[1]->laz+=n->laz;
        n->laz=0;
    }
    void qujianadd(node *n,int le,int ri,int add)
    {
        if(n->l==le&&n->r==ri)
        {
            n->laz+=add;
            return;
        }
        pushdown(n);
        if(n->ch[0]->r>=ri)
            qujianadd(n->ch[0],le,n->ch[0]->r,add);
        else if(n->ch[1]->l<=le)
            qujianadd(n->ch[1],n->ch[1]->l,ri,add);
        else
        {
            qujianadd(n->ch[0],le,n->ch[0]->r,add);
            qujianadd(n->ch[1],n->ch[1]->l,ri,add);
        }
        pushdown(n->ch[0]);
        pushdown(n->ch[1]);
        n->s=n->ch[0]->s+n->ch[1]->s;
    }
    int qujianhe(node *n,int le,int ri)
    {
        pushdown(n);
        if(n->l==le&&n->r==ri)
            return n->s;
        if(n->ch[0]->r>=ri)
            return qujianhe(n->ch[0],le,ri);
        else if(n->ch[1]->l<=le)
            return qujianhe(n->ch[1],le,ri);
        else
            return qujianhe(n->ch[0],le,n->ch[0]->r)+qujianhe(n->ch[1],n->ch[1]->l,ri);
    }
}