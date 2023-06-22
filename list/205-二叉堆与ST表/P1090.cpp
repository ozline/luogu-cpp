/**
 * @author OZLIINEX
 * @brief P1090 [NOIP2004 提高组] 合并果子 / [USACO06NOV] Fence Repair G
 * @date 2022-07-25
 */

#include "header.hpp"
#define MAXN 500001

void solve()
{

    int n = read();

    int num;

    priority_queue<int , vector<int> , greater<int> > Q;

    for(int i=1;i<=n;i++)
    {
        num = read();
        Q.push(num);
    }

    ll ans = 0;

    while(Q.size() > 1)
    {
        ll a1 = Q.top(); Q.pop();
        ll a2 = Q.top(); Q.pop();
        ll combine = a1+a2;
        // debug("a1:%lld a2:%lld combine:%lld QSize:%lu\n",a1,a2,combine,Q.size());
        ans += combine;
        Q.push(combine);
    }

    writeln(ans);
}