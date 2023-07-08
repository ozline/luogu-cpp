/**
 * @file P2367.cpp
 * @author ozlinex
 * @brief P2367 语文成绩
 * @date 2023-07-08
 */

#include "header.hpp"
#define MAXN 5000001

int n, p;
int a[MAXN];
int b[MAXN], addsum;
int ans = INF;

void solve()
{
    n = read(), p = read();
    req(i, 1, n) a[i] = read();

    while(p--)
    {
        int x = read(), y = read(), z = read();
        b[x] += z;
        b[y + 1] -= z;
    }

    req(i, 1, n)
    {
        addsum += b[i];
        ans = min(ans, a[i] + addsum);
    }

    printf("%d\n", ans);
}