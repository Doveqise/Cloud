#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
struct bignum
{
    int len, s[N];
    bignum()
    {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    bignum(int num) { *this = num; }
    bignum(char *num) { *this = num; }
    bignum operator=(int num)
    {
        char c[N];
        sprintf(c, "%d", num);
        *this = c;
        return *this;
    }
    bignum operator=(const char *num)
    {
        len = strlen(num);
        for (int i = 0; i < len; i++)
            s[i] = num[len - 1 - i] - '0';
        return *this;
    }
    string str()
    {
        string res = "";
        for (int i = 0; i < len; i++)
            res = (char)(s[i] + '0') + res;
        return res;
    }
    void clean()
    {
        while (len > 1 && !s[len - 1])
            len--;
    }
    bignum operator+(const bignum &b)
    {
        bignum c;
        c.len = 0;
        for (int i = 0, g = 0; g || i < len || i < b.len; i++)
        {
            int x = g;
            if (i < len)
                x += s[i];
            if (i < b.len)
                x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }
    bignum operator-(const bignum &b)
    {
        bignum c;
        c.len = 0;
        int x;
        for (int i = 0, g = 0; i < len; i++)
        {
            x = s[i] - g;
            if (i < b.len)
                x -= b.s[i];
            if (x >= 0)
                g = 0;
            else
            {
                x += 10;
                g = 1;
            };
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    }
    bignum operator*(const bignum &b)
    {
        bignum c;
        c.len = len + b.len;
        for (int i = 0; i < len; i++)
            for (int j = 0; j < b.len; j++)
                c.s[i + j] += s[i] * b.s[j];
        for (int i = 0; i < c.len - 1; i++)
        {
            c.s[i + 1] += c.s[i] / 10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }
    bool operator<(const bignum &b)
    {
        if (len != b.len)
            return len < b.len;
        for (int i = len - 1; i >= 0; i--)
            if (s[i] != b.s[i])
                return s[i] < b.s[i];
        return false;
    }
    bignum operator+=(const bignum &b)
    {
        *this = *this + b;
        return *this;
    }
    bignum operator-=(const bignum &b)
    {
        *this = *this - b;
        return *this;
    }
};
istream &operator>>(istream &in, bignum &x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream &operator<<(ostream &out, bignum &x)
{
    out << x.str();
    return out;
}
bignum f[2005]={0,0,1,2};
long long n;
signed main()
{
    cin>>n;
    if(n<4)
    {
        cout<<f[n]<<endl;
        return 0;
    }
    for(int i=4;i<=n;i++)
        f[i]=(f[i-1]+f[i-2])*(i-1);
    cout<<f[n]<<endl;
    return 0;
}