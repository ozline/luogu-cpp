/**
 * @author OZLIINEX
 * @brief P3865 【模板】ST 表
 * @date 2023-04-02
 */

// st表模板题
// 好好背吧！

#include "header.hpp"
#define MAXN 200001

const int p = 21;

int n, m;
int maxn[MAXN][p];
int logn[MAXN];


void init_log()
{
    logn[1] = 0;
    req(i, 2, MAXN) logn[i] = logn[i >> 1] + 1;
}

int st(int l, int r)
{
    int k = logn[r - l + 1];
    return max(maxn[l][k], maxn[r - (1 << k) + 1][k]);
}

void solve()
{
    init_log();
    n = read(), m = read();
    req(i, 1, n) maxn[i][0] = read();

    req(i, 1, p) req(j, 1, n - (1 << i) + 1)
    {
        maxn[j][i] = max(maxn[j][i - 1], maxn[j + (1 << (i - 1))][i - 1]);
    }

    req(i, 1, m)
    {
        int l = read(), r = read();
        writeln(st(l, r));
    }
}