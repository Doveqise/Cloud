#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e7;
int n, Q, m, T, h[10], t[10], tmp; 
double u, v, p;
int q[4][MAXN], ans[MAXN];
inline void find(int x){
    int num = 0, sum = 0;
    for(int i = 1; i <= 3; i++){
        if(i == 1 && q[i][h[i]] + x * Q > sum && h[i] < t[i]) num = i, sum = q[i][h[i]] + x * Q;
        else if(q[i][h[i]] + (x-h[i])*Q > sum && h[i] < t[i]) num= i, sum = q[i][h[i]] + (x-h[i])*Q;
    }
    ans[x+1] = sum; tmp = sum; q[num][h[num]++];
}
int len[MAXN];
void print(){
    int num = 0;

    for(int i = T, tot = 1; i <= m && tot <= m/T; i += T, tot++)
        printf("%d ",ans[i]);
    printf("\n");    

    for(int i = 1; i <= 3; i++){
        for(int j = h[i]; j < t[i]; j++){
            if(i == 1 && h[i] < t[i]) len[++num] = q[i][j] + (m) * Q;
            else if(h[i] < t[i]) len[++num] = q[i][j] + (m-j)*Q;
        }
    }
    sort(len+1, len+num+1, greater<int>());
    for(int i = T, tot = 1; i <= num && tot <= (n+m)/T; i += T, tot++)
        printf("%d ",len[i]);
}
int main(){
    scanf("%d%d%d%lf%lf%d", &n, &m, &Q, &u, &v, &T);
    p = u / v; 
    for(int i = 1; i <= 3; i++) h[i] = t[i] = 1; 
    for(int i = 1; i <= n; i++) scanf("%d",&q[1][i]),t[1]++;

    sort(q[1]+h[1], q[1]+t[1], greater<int>());

    for(int i = 1; i <= m; i++){
        find(i-1);
        double a = floor(tmp * p), b = tmp - a;
        if(a < b) swap(a, b);
        q[2][t[2]++] = a; q[3][t[3]++] = b;
    }

    print();
    return 0;
}