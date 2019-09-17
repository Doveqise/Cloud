#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = n, t; i >= 0; i--)
    {
        scanf("%d", &t);
        if (t)
        {
            if (i != n && t > 0)
                printf("+");
            if (abs(t) > 1 || i == 0)
                printf("%d", t);
            if (t == -1 && i)
                printf("-");
            if (i > 1)
                printf("x^%d", i);
            if (i == 1)
                printf("x");
        }
    }
}