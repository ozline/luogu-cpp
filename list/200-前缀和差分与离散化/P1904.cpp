/**
 * @file P1904.cpp
 * @author ozlinex
 * @brief P1904 天际线
 * @date 2023-07-09
 */


// 这道题因为数据量的原因所以写的很暴力
// 标准做法应该是离散化 + 线段树 + 扫描线

#include "header.hpp"
#define MAXN 500001


ll ans[MAXN];

void solve()
{
    ll l, r, h;
    while(cin >> l >> h >> r)
    {
        req(i, l, r - 1) ans[i] = max(ans[i], h);
    }

    h = 0;
    req(i, 0, 1e5 - 1)
    {
        if(h != ans[i])
        {
            h = ans[i];
            printf("%d %d ", i, h);
        }
    }
}