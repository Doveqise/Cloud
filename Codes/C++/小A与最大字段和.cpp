#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
long long A[maxn], B[maxn], a[maxn], st[maxn], hi;
long long L(int j) {return A[j - 1] - B[j - 1] * (j - 1);}
double mat(double a, double b, double c, double d) {return (b - d) / (a - c);}
long long R(int i, int j) {return A[j] - A[i - 1] - (B[j] - B[i - 1]) * (i - 1);}
int main()
{
    int n; scanf("%d", &n);
    long long ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        A[i] = A[i - 1] + a[i] * i;
        B[i] = B[i - 1] + a[i];
        ans = max(ans, R(i, i));
    }
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = hi;
        while (l + 5 < r)
        {
            int ll = l + (r - l) / 3;
            int rr = r - (r - l) / 3;
            if (R(st[ll], i) > R(st[rr], i)) r = rr;
            else l = ll;
        }
        for (int j = l; j <= r; j++) ans = max(ans, R(st[j], i));
        while (hi > 1 && mat(i, L(i), st[hi], L(st[hi])) < mat(st[hi], L(st[hi]), st[hi - 1], L(st[hi - 1]))) --hi;
        st[++hi] = i;
    }
    printf("%lld\n", ans);
    return 0;
}