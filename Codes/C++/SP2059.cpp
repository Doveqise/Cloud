#include <bits/stdc++.h>
#define N 100000
#define swap(x, y) (x ^= y ^= x ^= y)
#define INF 1e9
using namespace std;
int n;
struct Data
{
    int pos, val;
    inline friend bool operator<(Data x, Data y) { return x.val ^ y.val ? x.val < y.val : x.pos < y.pos; }
} a[N + 5];
class Class_FIO
{
private:
#define Fsize 100000
#define tc() (A == B && (B = (A = Fin) + fread(Fin, 1, Fsize, stdin), A == B) ? EOF : *A++)
#define pc(ch) (FoutSize ^ Fsize ? Fout[FoutSize++] = ch : (fwrite(Fout, 1, Fsize, stdout), Fout[(FoutSize = 0)++] = ch))
#define Isi(x) (typeid(x).name() == typeid(1).name())
#define Isc(x) (typeid(x).name() == typeid('a').name())
    int Top, FoutSize;
    char ch, *A, *B, Fin[Fsize], Fout[Fsize], Stack[Fsize];

public:
    Class_FIO() { A = B = Fin; }
    template <typename I > inline void read(I &x)
    {
        x = 0;
        while (!isdigit(ch = tc()))
            ;
        while (x = (x << 3) + (x << 1) + (ch & 15), isdigit(ch = tc()))
            ;
    }
    template <typename I > inline void write(I x)
    {
        if (Isi(x))
        {
            while (Stack[++Top] = x % 10 + 48, x /= 10)
                ;
            while (Top)
                pc(Stack[Top--]);
        }
        if (Isc(x))
            pc(x);
    }
    template <typename I, typename... A>
    inline void read(I &x, A &... y) { read(x), read(y...); }
    template <typename I, typename... A>
    inline void write(I x, A... y) { write(x), write(y...); }
    inline void clear() { fwrite(Fout, 1, FoutSize, stdout), FoutSize = 0; }
} F;
class Class_Splay 
{
private:
#define SIZE N
#define PushUp(x) (node[x].Size = node[node[x].Son[0]].Size + node[node[x].Son[1]].Size + 1)
#define Rever(x) (swap(node[x].Son[0], node[x].Son[1]), node[x].Rev ^= 1)
#define PushDown(x) (node[x].Rev && (Rever(node[x].Son[0]), Rever(node[x].Son[1]), node[x].Rev = 0))
#define Which(x) (node[node[x].Father].Son[1] == x)
#define Connect(x, y, d) (node[node[x].Father = y].Son[d] = x)
#define Split(x, y) (Splay(get_pos(x), rt), Splay(get_pos((y) + 2), node[rt].Son[1]), node[node[rt].Son[1]].Son[0])
    int rt;
    struct Tree
    {
        int Size, Rev, Father, Son[2];
    } node[SIZE + 5];
    inline void Rotate(int x, int &k)
    {
        register int fa = node[x].Father, pa = node[fa].Father, d = Which(x);
        PushDown(fa), PushDown(x),
            (fa ^ k ? node[pa].Son[Which(fa)] = x : k = x), node[x].Father = pa, Connect(node[x].Son[d ^ 1], fa, d), Connect(fa, x, d ^ 1), PushUp(fa), PushUp(x);
    }
    inline void Splay(int x, int &k)
    {
        register int fa;
        while (x ^ k)
            fa = node[x].Father, fa ^ k && (Rotate(Which(x) ^ Which(fa) ? x : fa, k), 0), Rotate(x, k);
    }
    inline void Build(int l, int r, int &rt)
    {
        register int mid = l + r >> 1;
        if (node[rt = mid].Size = 1, !(l ^ r))
            return;
        l<mid && (Build(l, mid - 1, node[rt].Son[0]), node[node[rt].Son[0]].Father = rt),
          r>
                mid && (Build(mid + 1, r, node[rt].Son[1]), node[node[rt].Son[1]].Father = rt),
            PushUp(rt);
    }
    inline int get_pos(int rk)
    {
        register int x = rt;
        while (x)
        {
            if (PushDown(x), node[node[x].Son[0]].Size >= rk)
                x = node[x].Son[0];
            else if (!(rk -= node[node[x].Son[0]].Size + 1))
                return x;
            else
                x = node[x].Son[1];
        }
    }

public:
    inline void Init(int len) { Build(1, len + 2, rt); }
    inline int GetAns(int x)
    {
        register int k, ans;
        Splay(a[x].pos + 1, rt), ans = node[node[rt].Son[0]].Size, k = Split(x, ans), Rever(k); //找到ans，然后翻转
        return ans;                                                                             //返回答案
    }
#undef SIZE
} Splay;
int main()
{
    register int i, p;
    F.read(n); 
    while (n)
    {
    for (i = 1; i <= n; ++i)
        F.read(a[a[i].pos = i].val); 
    for (sort(a + 1, a + n + 1), Splay.Init(n), i = 1; i <= n; ++i)
        F.write(p = Splay.GetAns(i), ' ');
        puts("");
        F.clear();
        F.read(n);
    }
    return 0;
}