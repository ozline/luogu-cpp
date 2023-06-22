/**
 * @author OZLIINEX
 * @brief P1216 [USACO1.5][IOI1994]数字三角形 Number Triangles
 * @date 2023-04-07
 */

// 是我生日的PID诶
// 这道题是倒着跑一遍dp就可以了

#include "header.hpp"
#define MAXN 2001

int n;
int a[MAXN][MAXN];
int ans[MAXN][MAXN];


void solve()
{
    n = read();
    req(i, 1, n) req(j, 1, i) a[i][j] = read(), ans[i][j] = a[i][j];


    for(int i = n - 1; i > 0; i--)
    {
        req(j, 1, i) ans[i][j] = max(ans[i + 1][j], ans[i + 1][j + 1]) + a[i][j];
    }

    printf("%d\n", ans[1][1]);
}