#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int mod=1e8 - 3;
int e[maxn],
c[maxn],
n,
ans;

struct node {
    int dat,
    pos;

    bool operator < (const node b) const {
        return dat < b.dat;
    }
}

a[maxn],
b[maxn];

int lowbit(int x) {
    return x & (-x);
}

void add(int pos, int val) {
    for (; pos <=n; pos +=lowbit(pos)) e[pos]=(e[pos] + val) % mod;
}

int query(int pos) {
    int res=0;
    for (; pos; pos -=lowbit(pos)) res=(res + e[pos]) % mod;
    return res;
}

signed main() {
    scanf("%d", & n);

    for (int i=1; i <=n; i++) {
        scanf("%d", & a[i].dat);
        a[i].pos=i;
    }

    sort(a + 1, a + 1 + n);

    for (int i=1; i <=n; i++) {
        scanf("%d", & b[i].dat);
        b[i].pos=i;
    }

    sort(b + 1, b + 1 + n);
    for (int i=1; i <=n; i++) c[a[i].pos]=b[i].pos;

    for (int i=1; i <=n; i++) {
        add(c[i], 1);
        ans=(ans + i - query(c[i])) % mod;
    }

    printf("%d\n", ans);
    return 0;
}