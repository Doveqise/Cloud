#include <bits/stdc++.h>
using namespace std;
char a[12][12], b[12][12], t1[12][12], t2[12][12];
int n;
bool chk()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (t1[i][j] != b[i][j])
                return 0;
    return 1;
}
bool ch1()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            t1[j][n - i + 1] = a[i][j];
    return chk();
}
bool ch2()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            t1[n - i + 1][n - j + 1] = a[i][j];
    return chk();
}
bool ch3()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            t1[j][i] = a[i][j];
    return chk();
}
bool ch4()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            t1[i][n - j + 1] = a[i][j];
    return chk();
}
bool ch5()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            t2[i][n - j + 1] = a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            t1[j][n - i + 1] = t2[i][j];
    return chk();
}
bool ch6()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            t2[i][n - j + 1] = a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            t1[n - i + 1][n - j + 1] = t2[i][j];
    return chk();
}
bool ch7()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            t2[i][n - j + 1] = a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            t1[i][n - j + 1] = t2[i][j];
    return chk();
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    for (int i = 1; i <= 6; i++)
    {
        if (i == 1)
            if (ch1())
            {
                puts("1");
                return 0;
            }
        if (i == 2)
            if (ch2())
            {
                puts("2");
                return 0;
            }
        if (i == 3)
            if (ch3())
            {
                puts("3");
                return 0;
            }
        if (i == 4)
            if (ch4())
            {
                puts("4");
                return 0;
            }
        if (i == 5)
            if (ch5() || ch6() || ch7())
            {
                puts("5");
                return 0;
            }
        if (i == 6)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (a[i][j] != b[i][j])
                    {
                        puts("7");
                        return 0;
                    }
    }
    puts("6");
    return 0;
}