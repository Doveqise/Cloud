#include<bits/stdc++.h>
#define it int
#define R register it
#define ii inline it
#define iv inline void
#define co continue
#define rt return
#define sc scanf
#define mn 2000005
using namespace std;struct Node{it u,v,ne;}ed[mn];struct Tree{it f,l,r,w,sz;}tr[mn];
it a[mn],b[mn],f[mn],ix[mn],so[mn],tp[mn],tt[mn],dt[mn],he[mn],m,n,r,p,x,y,z,cnt,nm,op;
iv ud(it k){tr[k].w=(tr[k<<1].w+tr[k<<1|1].w+p)%p;}iv ad(it u,it v){ed[++nm].u=u;ed[nm].v=v;ed[nm].ne=he[u];he[u]=nm;}
iv pd(it k){if(!tr[k].f)rt;(tr[k<<1].w+=tr[k<<1].sz*tr[k].f)%=p;(tr[k<<1|1].w+=tr[k<<1|1].sz*tr[k].f)%=p;
	(tr[k<<1].f+=tr[k].f)%=p;(tr[k<<1|1].f+=tr[k].f)%=p;tr[k].f=0;}
iv IA(it k,it l,it r,it vl){if(l<=tr[k].l&&tr[k].r<=r){tr[k].w+=tr[k].sz*vl;tr[k].f+=vl;rt;}
	pd(k);it md=(tr[k].l+tr[k].r)>>1;if(l<=md)IA(k<<1,l,r,vl);if(r>md)IA(k<<1|1,l,r,vl);ud(k);}
iv bd(it k,it l,it r){tr[k].l=l,tr[k].r=r,tr[k].sz=r-l+1;
	if(l==r){tr[k].w=a[l];rt;}it md=(l+r)>>1;bd(k<<1,l,md),bd(k<<1|1,md+1,r);ud(k);}
iv D2(it u,it f){ix[u]=++cnt;a[cnt]=b[u];tp[u]=f;if(!so[u])rt;
	D2(so[u],f);for(R i=he[u];i;i=ed[i].ne) if(!ix[ed[i].v]) D2(ed[i].v,ed[i].v);}
iv TA(it x,it y,it vl){while(tp[x]!=tp[y]){
	if(dt[tp[x]]<dt[tp[y]]) swap(x,y);IA(1,ix[tp[x]],ix[x],vl);x=f[tp[x]];}if(dt[x]>dt[y])swap(x,y);IA(1,ix[x],ix[y],vl);}
ii IS(it k,it l,it r){it ans=0;if(l<=tr[k].l&&tr[k].r<=r) rt tr[k].w;pd(k);
	it md=(tr[k].l+tr[k].r)>>1;if(l<=md)(ans+=IS(k<<1,l,r))%=p;if(r>md)(ans+=IS(k<<1|1,l,r))%=p;rt ans;}
iv D1(it u,it ff){dt[u]=dt[ff]+1;f[u]=ff;so[u]=0;tt[u]=1;for(R i=he[u];i;i=ed[i].ne){
	if(ed[i].v==ff)co;D1(ed[i].v,u);tt[u]+=tt[ed[i].v];if(tt[ed[i].v]>tt[so[u]])so[u]=ed[i].v;}}
iv TS(it x,it y){it ans=0;while(tp[x]!=tp[y]){if(dt[tp[x]]<dt[tp[y]]) swap(x,y);(ans+=IS(1,ix[tp[x]],ix[x]))%=p;
	x=f[tp[x]];}if(dt[x]>dt[y])swap(x,y);(ans+=IS(1,ix[x],ix[y]))%=p;printf("%d\n",ans);rt;}
it main(){sc("%d%d%d%d",&n,&m,&r,&p);for(R i=1;i<=n;++i)sc("%d",&b[i]);for(R i=1;i<=n-1;++i){
	sc("%d%d",&x,&y);ad(x,y),ad(y,x);}D1(r,0);D2(r,r);bd(1,1,n);for(R i=1;i<=m;++i){sc("%d",&op);
	if(op==1){sc("%d%d%d",&x,&y,&z);TA(x,y,z%p);}else if(op==2){sc("%d%d",&x,&y);TS(x,y);}
	else if(op==3){sc("%d%d",&x,&z);IA(1,ix[x],ix[x]+tt[x]-1,z%p);}else {sc("%d",&x);printf("%d\n",IS(1,ix[x],ix[x]+tt[x]-1));}}rt 0;}
