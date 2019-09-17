#include <bits/stdc++.h>
using namespace std;
char s[10][10];
int dic = 0, x, y;
int db[5] = {0, 2, 1, 4, 3};
int dr[5] = {0, 4, 3, 1, 2};
int dl[5] = {0, 3, 4, 2, 1};
char pri[4] = {'^', 'v', '<', '>'};
void debug()
{
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (x == i && y == j)
                cout << pri[dic - 1];
            else
                cout << s[i][j];
        }
        cout << endl;
    }
}
void go_up(int k)
{
    int dx = x, dy = y;
    for (int i = x - 1; i >= 1; i--)
    {
        if (dx == 1)
            break;
        if (!k)
            break;
        if (s[i][y] == '.')
        {
            dx--;
            k--;
            continue;
        }
        if (s[i][y] != '.')
        {
            int flag = i;
            for (int j = i; j >= 1; j--)
                if (s[j][y] == '.' || j == 1)
                {
                    flag = j;
                    break;
                }
            for (int j = flag; j <= i; j++)
                s[j][y] = s[j + 1][y];
            dx--, k--;
        }
    }
    x = dx;
}
void go_down(int k)
{
    int dx = x, dy = y;
    for (int i = x + 1; i <= 8; i++)
    {
        if (dx == 8)
            break;
        if (!k)
            break;
        if (s[i][y] == '.')
        {
            dx++;
            k--;
            continue;
        }
        if (s[i][y] != '.')
        {
            int flag = i;
            for (int j = i; j <= 8; j++)
                if (s[j][y] == '.' || j == 8)
                {
                    flag = j;
                    break;
                }
            for (int j = flag; j >= i; j--)
                s[j][y] = s[j - 1][y];
            dx++, k--;
        }
    }
    x = dx;
}
void go_lf(int k)
{
    int dy = y;
    for (int i = y - 1; i >= 1; i--)
    {
        if (dy == 1)
            break;
        if (k == 0)
            break;
        if (s[x][i] == '.')
        {
            dy--;
            k--;
            continue;
        }
        if (s[x][i] != '.')
        {
            int flag = i;
            for (int j = i; j >= 1; j--)
            {
                if (s[x][j] == '.' || j == 1)
                {
                    flag = j;
                    break;
                }
            }
            for (int j = flag; j <= i; j++)
                s[x][j] = s[x][j + 1];
            dy--, k--;
        }
    }
    y = dy;
}
void go_ri(int k)
{
    int dy = y;
    for (int i = y + 1; i <= 8; i++)
    {
        if (dy == 8)
            break;
        if (!k)
            break;
        if (s[x][i] == '.')
        {
            dy++;
            k--;
            continue;
        }
        if (s[x][i] != '.')
        {
            int flag = i;
            for (int j = i; j <= 8; j++)
            {
                if (s[x][j] == '.' || j == 8)
                {
                    flag = j;
                    break;
                }
            }
            for (int j = flag; j >= i; j--)
                s[x][j] = s[x][j - 1];
            dy++, k--;
        }
    }
    y = dy;
}
int main()
{
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == '^')
            {
                dic = 1;
                s[i][j] = '.';
                x = i, y = j;
            }
            if (s[i][j] == 'v')
            {
                dic = 2;
                x = i, y = j;
                s[i][j] = '.';
            }
            if (s[i][j] == '<')
            {
                x = i, y = j;
                s[i][j] = '.';
                dic = 3;
            }
            if (s[i][j] == '>')
            {
                x = i, y = j;
                s[i][j] = '.';
                dic = 4;
            }
        }
    string a, b;
    int c;
    int t = 0;
    while (1)
    {
        cin >> a;
        if (a == "#")
            break;
        else if (a == "turn")
        {
            cin >> b;
            if (b == "right")
                dic = dr[dic];
            else if (b == "left")
                dic = dl[dic];
            else if (b == "back")
                dic = db[dic];
        }
        else if (a == "move")
        {
            cin >> c;
            if (dic == 1)
                go_up(c);
            else if (dic == 2)
                go_down(c);
            else if (dic == 3)
                go_lf(c);
            else if (dic == 4)
                go_ri(c);
        }
    }
    debug();
}