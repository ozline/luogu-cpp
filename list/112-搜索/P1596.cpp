/**
 * @author OZLIINEX
 * @brief P1596 [USACO10OCT]Lake Counting S
 * @date 2023-03-26
 */

// 还是忘记了，cin后如果有换行，同时新的行要getchar的话，我们要先getchar一次

#include "header.hpp"
#define MAXN 201


int n, m;
int a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int ans;

int px[] = {1, -1, 0, 0, 1, 1, -1, -1};
int py[] = {0, 0, 1, -1, 1, -1, 1, -1};

// 打标记
void dfs(int x, int y)
{
    int xx, yy;
    vis[x][y] = 1;
    req(i, 0, 7)
    {
        xx = x + px[i], yy = y + py[i];

        if(xx > 0 && yy > 0 && xx <= n && yy <= m && a[xx][yy] && !vis[xx][yy]) dfs(xx, yy);
    }
}

void solve()
{
    char ch;
    cin >> n >> m;
    getchar();
    req(i, 1, n) // x
    {
        req(j, 1, m) // y
        {
            ch = getchar();
            if(ch == 'W') a[i][j] = 1;
            if(ch == '.') a[i][j] = 0;
        }
        getchar();
    }

    // req(i, 1, n)
    // {
    //     req(j, 1, m) putchar(a[i][j] + 48);
    //     putchar('\n');
    // }

    req(i, 1, n) req(j, 1, m)
    {
        if(a[i][j] && !vis[i][j])
        {
            dfs(i, j);
            ans++;
        }
    }

    printf("%d\n", ans);

}