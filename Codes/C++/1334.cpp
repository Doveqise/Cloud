/*#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;//Ð¡¸ù¶Ñ
}
signed main(){
	vector<long long>h;
	long long n,t,ans=0;
	scanf("%lld",&n);
	make_heap(h.begin(),h.end(),cmp);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&t);
		h.push_back(t);
		push_heap(h.begin(),h.end(),cmp);
	}
	for(long long i=1;i<n;i++){
		int a=h[0],b=h[1];
		pop_heap(h.begin(),h.end(),cmp);
		h.pop_back();
		pop_heap(h.begin(),h.end(),cmp);
		h.pop_back();
		h.push_back(a+b);
		push_heap(h.begin(),h.end(),cmp);
		ans+=a+b;
	}
	printf("%lld",ans);
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
	int n;
	long long ans=0;
	scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    while(1){
        int j=0;
        while(a[j]==0) j++;
        if(j==n) break;
        else {
            a[j]+=a[j+1];
            ans+=a[j];
            for(int l=j+1;l<n;l++) a[l]=a[l+1];
            n--;
        }
        for(int l=j;l<n;l++) if(a[l]>a[l+1]) swap(a[l],a[l+1]);
    }
    printf("%lld",ans);
    return 0;
    }
