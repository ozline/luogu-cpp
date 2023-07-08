/**
 * @file P1255.cpp
 * @author ozlinex
 * @brief P1255 数楼梯
 * @date 2023-06-23
 */

#include "header.hpp"
#define MAXN 50001

ll ans;
ll vis[MAXN];

ll loop(int last)
{
    if(last == 0) {
        ans++;
        return 1;
    }

    if(vis[last] != -1) {
        ans += vis[last];
        return vis[last];
    }

    vis[last] = 0;
    if(last > 0) vis[last] += loop(last - 1);
    if(last > 1) vis[last] += loop(last - 2);
}

void solve()
{
    req(i, 0, MAXN - 1) vis[i] = -1;
    int n = read();
    loop(n);
    printf("%lld", ans);
    debugvar(vis[n]);
}