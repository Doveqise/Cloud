#include <bits/stdc++.h>
const long long MAXN = 1e6 + 10;
const long long p = 998244353;
using namespace std;
long long n,m,i,j,k;
long long R[MAXN],a[MAXN],b[MAXN],wn[MAXN];
long long read() {
    long long res = 0;char c;bool sign = 0;
    for(c = getchar();!isdigit(c);c = getchar()) sign |= c == '-';
    for(;isdigit(c);c = getchar()) res = (res << 1) + (res << 3) + (c ^ 48);
    return sign ? -res : res;
}
long long fpow(long long a,long long b,long long mod = p) {
    long long res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        b >>= 1;a = (a * a) % mod;
    }
    return res;
}
void NTT(long long a[],long long len,long long on) {
   for(long long i = 0, j = 0; i < len; ++i) {
        if (i > j) swap(a[i], a[j]);
        for (long long l = len >> 1; (j ^= l) < l; l >>= 1);
    }
    long long id = 0;
    for(long long i = 1;i < len;i <<= 1) {
        id++;
        for(long long j = 0;j < len;j += i << 1) {
            long long w = 1;
            for(long long k = 0;k < i;k++) {
                long long x = a[j + k] % p;
                long long y = w * a[j + k + i] % p;
                a[j + k] = (x + y) % p;
                a[j + k + i] = (x - y + p) % p;
                w = w * wn[id] % p;
            }
        }
    }
    if(!~on) {
        reverse(a + 1,a + len);
        long long inv = fpow(len,p - 2,p);
        for(long long i = 0;i < len;i++) a[i] = a[i] * inv % p;
    }
    return;
} 
void calc(long long deg,long long *a,long long *b) {
    static long long tmp[MAXN];
    if(deg == 1) b[0] = fpow(a[0],p - 2);
    else {
        calc((deg + 1) >> 1,a,b);
        long long _p = 1;
        while(_p < deg << 1) _p <<= 1;
        copy(a,a + deg,tmp);
        fill(tmp + deg,tmp + _p,0);
        NTT(tmp,_p,1);NTT(b,_p,1);
        for(long long i = 0;i < _p;i++) {
            b[i] = (2 - b[i] * tmp[i] % p + p) % p * b[i] % p; 
        }
        NTT(b,_p,-1);fill(b + deg,b + _p,0);
    }
    return;
}
signed main() {
    for(long long i = 0;i < 21;i++) wn[i] = fpow(3,(p - 1) / (1 << i),p);
    n = read();
    for(long long i = 0;i < n;i++) a[i] = read();
    long long li = 1,t = 0;while(li < n << 1) li <<= 1,t++;
    calc(n,a,b);
    for(long long i = 0;i < n;i++) printf("%lld ",(b[i] + p) % p);
    return 0;
}
