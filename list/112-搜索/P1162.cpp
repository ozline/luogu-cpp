/**
 * @author OZLIINEX
 * @brief P1162 填涂颜色
 * @date 2023-03-26
 */

#include "header.hpp"
#define MAXN 101

int n;
int a[MAXN][MAXN];

int px[] = {0, 0, 1, -1};
int py[] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    if(a[x][y] != 0) return;
    a[x][y] = 3;
    req(i, 0, 3)
    {
        int xx = x + px[i], yy = y + py[i];

        if(xx > 0 && xx <=n && yy > 0 && yy <=n && a[xx][yy] == 0) dfs(xx, yy);
    }
}

void solve()
{
    cin >> n;
    req(i, 1, n) req(j, 1, n) cin >> a[i][j];



    // 只要把边缘都搜一遍就行了嘛
    req(i, 1, n) dfs(1, i), dfs(n, i);
    req(i, 2, n - 1) dfs(i, 1), dfs(i, n);

    req(i, 1, n)
    {
        req(j, 1, n)
        {
            if(a[i][j] == 1) putchar(49);
            else if(a[i][j] == 3) putchar(48);
            else putchar(50);

            if(j != n) putchar(' ');
        }

        putchar('\n');
    }

    return;
}