#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxn = 3e4+5;
const long long maxx = 1e18;
struct BigIntenger
{  
    int d[maxn], len;  
    void clean()
    { 
        while(len > 1 && !d[len-1]) 
            len--; 
    }  
    BigIntenger()
    { 
        memset(d, 0, sizeof(d)); 
        len = 1; 
    }  
    BigIntenger(int num)   
    { 
        *this = num; 
    }   
    BigIntenger(char* num) 
    { 
        *this = num; 
    }  
    BigIntenger operator = (const char* num)
    {  
        memset(d, 0, sizeof(d)); 
        len = strlen(num);  
        for(int i = 0; i < len; i++) 
            d[i] = num[len-1-i] - '0';  
        clean();  
        return *this;  
    }  
    BigIntenger operator = (int num)
    {  
        char s[20]; 
        sprintf(s, "%d", num);  
        *this = s;  
        return *this;  
    }  
    BigIntenger operator + (const BigIntenger& b)
    {  
        BigIntenger c = *this; 
        int i;  
        for (i = 0; i < b.len; i++)
        {  
            c.d[i] += b.d[i];  
            if (c.d[i] > 9) 
                c.d[i]%=10, c.d[i+1]++;  
        }  
        while (c.d[i] > 9) 
            c.d[i++]%=10, c.d[i]++;  
        c.len = max(len, b.len);  
        if (c.d[i] && c.len <= i) 
            c.len = i+1;  
        return c;  
    }  
    BigIntenger operator - (const BigIntenger& b)
    {  
        BigIntenger c = *this; 
        int i;  
        for (i = 0; i < b.len; i++)
        {  
            c.d[i] -= b.d[i];  
            if (c.d[i] < 0) 
                c.d[i]+=10, c.d[i+1]--;  
        }  
        while (c.d[i] < 0) 
            c.d[i++]+=10, c.d[i]--;  
        c.clean();  
        return c;  
    }  
    BigIntenger operator * (const BigIntenger& b)const
    {  
        int i, j; 
        BigIntenger c; 
        c.len = len + b.len;   
        for(j = 0; j < b.len; j++) 
            for(i = 0; i < len; i++)   
                c.d[i+j] += d[i] * b.d[j];  
        for(i = 0; i < c.len-1; i++)  
            c.d[i+1] += c.d[i]/10, c.d[i] %= 10;  
        c.clean();  
        return c;  
    }  
    BigIntenger operator / (const BigIntenger& b)
    {  
        int i, j;  
        BigIntenger c = *this, a = 0;  
        for (i = len - 1; i >= 0; i--)  
        {  
            a = a*10 + d[i];  
            for (j = 0; j < 10; j++) 
                if (a < b*(j+1)) break;  
            c.d[i] = j;  
            a = a - b*j;  
        }  
        c.clean();  
        return c;  
    }  
    BigIntenger operator % (const BigIntenger& b)
    {  
        int i, j;  
        BigIntenger a = 0;  
        for (i = len - 1; i >= 0; i--)  
        {  
            a = a*10 + d[i];  
            for (j = 0; j < 10; j++) 
                if (a < b*(j+1)) 
                    break;  
            a = a - b*j;  
        }  
        return a;  
    }  
    BigIntenger operator += (const BigIntenger& b)
    {  
        *this = *this + b;  
        return *this;  
    }  
  
    bool operator <(const BigIntenger& b) const
    {  
        if(len != b.len) 
            return len < b.len;  
        for(int i = len-1; i >= 0; i--)  
            if(d[i] != b.d[i]) return d[i] < b.d[i];  
        return false;  
    }  
    bool operator >(const BigIntenger& b) const
    {
        return b < *this;
    }  
    bool operator<=(const BigIntenger& b) const
    {
        return !(b < *this);
    }  
    bool operator>=(const BigIntenger& b) const
    {
        return !(*this < b);
    }  
    bool operator!=(const BigIntenger& b) const
    {
        return b < *this || *this < b;
    }  
    bool operator==(const BigIntenger& b) const
    {
        return !(b < *this) && !(b > *this);
    }  
  
    string str() const
    {  
        char s[maxn]={};  
        for(int i = 0; i < len; i++) 
            s[len-1-i] = d[i]+'0';  
        return s;  
    }  
};  
istream& operator >> (istream& in, BigIntenger& x)  
{  
    string s; 
    in >> s;
    x = s.c_str();
    return in;
}  
ostream& operator << (ostream& out, const BigIntenger& x)  
{  
    out << x.str();  
    return out;  
}

int main()
{
    int n;
    scanf("%d",&n);
    if(!n){
        putchar(48);
        return 0;
    }
    BigIntenger a,b;
    a=1;
    b=2;
    for(int i=1;i<=n-1;i++){
        BigIntenger tmp=b;     
        b+=a;
        a=tmp;
    }
    cout<<b<<endl;
    return 0;
}