/**
 * @author OZLIINEX
 * @brief P1363 幻象迷宫
 * @date 2023-04-10
 */


// Ç++在对负数取余运算中，结果的符号与被除数相同，而不是与除数相同
// 例如，  -3 mod 2 = -1， 3 mod -2 = 1
// 但是在这道题中我们不能出现-1，我们实际上需要的是 n - 1(m - 1)
// 所以我们还需要 +n(m)

// 这道题本质是搜索
// 我们只需要判断能否以不同坐标回到同一个Node，这个Node就是题目中输入给的最小矩形中的点
// 对于dfs(x, y)，这里的x，y表示的是一个虚拟的，无限大的地图上的某个坐标
// 我们处理x, y，让它对应到最小矩形，再做判断即可

#include "header.hpp"
#define MAXN 1501

struct Node
{
    int x, y;
    bool vis;

    Node():x(0),y(0),vis(false){};
    Node(int a, int b, bool c):x(a),y(b),vis(c){};
};

int n, m, stx, sty;
bool a[MAXN][MAXN];
char ch;
Node mp[MAXN][MAXN];
// int mp[MAXN][MAXN][3];

int posx[] = {0, 0, 1, -1};
int posy[] = {1, -1, 0, 0};

bool flag;


bool check(int x, int y)
{
    int xx = x % n, yy = y % m;
    if(xx < 0) xx += n; if(xx < 0) xx += m;

    if (a[xx][yy] == 1) return false;
    if (!mp[xx][yy].vis || mp[xx][yy].x != x || mp[xx][yy].y != y) return true;
    return false;
}

// x, y: current position
void dfs(int x, int y)
{
    if(flag) return;
    int px = x % n, py = y % m;
    if(px < 0) px += n; if(py < 0) py += m;
    if(mp[px][py].vis && (mp[px][py].x != x || mp[px][py].y != y))
    {
        flag = true;
        return;
    }

    mp[px][py] = Node(x, y, true);

    req(i, 0, 3)
    {
        int nx = x + posx[i], ny = y + posy[i];
        if(check(nx, ny)) dfs(nx, ny);
    }
}

void solve()
{
    while(cin >> n >> m)
    {
        flag = false;
        req(i, 0, n) req(j, 0, m) a[i][j] = 0, mp[i][j] = Node();
        // READ
        req(i, 0, n - 1) req(j, 0, m - 1)
        {
            cin >> ch;
            if(ch == '#') a[i][j] = 1;
            if(ch == 'S') stx = i, sty = j;
        }
        // DFS
        dfs(stx, sty);
        puts(flag ? "Yes" : "No");
    }
}