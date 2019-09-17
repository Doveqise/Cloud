#include<bits/stdc++.h>
using namespace std;
const int INF_MAX = -999999999;
const int INF_MIN = 999999999;
const int maxn = 1e6+5;
int n,q,a,b,t=1,MAX=INF_MAX,MIN=INF_MIN;
struct node
{
    int l,r;
    int MAX,MIN;
    node *left, *right;
}
tree[maxn];
void build(node *root,int l,int r)
{
    root->l = l;
    root->r = r;
    root->MAX = INF_MAX;
    root->MIN = INF_MIN;
    if(l!=r)
    {
        root->left = &tree[t++];
        root->right = &tree[t++];
        build(root->left,l,(root->l+root->r)/2);
        build(root->right,(root->l+root->r)/2+1,r);
    }
}
void update(node *root,int i,int v)
{
    if(root->l == i&&root->r == i) 
    {
        root->MAX = root->MIN = v; 
        return ;
    }
    root->MIN = min(root->MIN,v);
    root->MAX = max(root->MAX,v);
    if(i<=(root->l+root->r)/2) 
    	update(root->left,i,v);
    else 
    	update(root->right,i,v);
}
void query(node *root,int l,int r)
{
    if(root->MAX<=MAX&&root->MIN>=MIN) 
    	return ;   
    if(l==root->l&&r==root->r) 
    {
        MIN = min(root->MIN,MIN);
        MAX = max(root->MAX,MAX);
        return ;
    }
    if(r<=(root->l+root->r)/2) 
    	query(root->left,l,r);
    else if(l>=(root->l+root->r)/2+1) 
    	query(root->right,l,r);
    else 
    {
        query(root->left,l,(root->l+root->r)/2);
        query(root->right,(root->l+root->r)/2+1,r);
    }
}
signed main()
{
    scanf("%d%d",&n,&q);
    build(tree,1,n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        update(tree,i,a);
    }
    while(q--)
    {
        scanf("%d%d",&a,&b);
        MAX = INF_MAX;
        MIN = INF_MIN;
        query(tree,a,b);
        printf("%d\n",MAX-MIN);
    }
    return 0;
}