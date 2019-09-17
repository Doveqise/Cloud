#include <bits/stdc++.h>
using namespace std;
vector<int>Vec;
int main(){
    int T;scanf("%d",&T);while(T--){int op,x;scanf("%d%d",&op,&x);
    switch(op){
            case 1:{int p=lower_bound(Vec.begin(),Vec.end(),x)-Vec.begin();Vec.insert(Vec.begin()+p,x);break;}
            case 2:{int p=lower_bound(Vec.begin(),Vec.end(),x)-Vec.begin();Vec.erase(Vec.begin()+p,Vec.begin()+p+1);break;}
            case 3:{int p=lower_bound(Vec.begin(),Vec.end(),x)-Vec.begin();printf("%d\n",p+1);break;}
            case 4:{printf("%d\n",Vec[x-1]);break;}
            case 5:{int p=lower_bound(Vec.begin(),Vec.end(),x)-Vec.begin();printf("%d\n",Vec[p-1]);break;}
            case 6:{printf("%d\n",*upper_bound(Vec.begin(),Vec.end(),x));break;}}}return 0;}
