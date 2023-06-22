/**
 * @author OZLIINEX
 * @brief P1478 陶陶摘苹果（升级版）
 * @date 2023-03-29
 */

#include "header.hpp"
#define MAXN 500001

struct Node
{
    ll x, y;

    bool operator<(const Node &a) const
    {
        return y < a.y;
    }
};

ll n, s, a, b;
Node p[MAXN];
ll ans;

void solve()
{
    n = read(), s = read(), a = read(), b = read();
    req(i, 1, n) p[i].x = read(), p[i].y = read();

    sort(p + 1, p + 1 + n);

    req(i, 1, n)
    {
        if(s < 0){s = 0, ans--; break;}
        if(p[i].x <= (a + b)) ans++, s -= p[i].y;
    }

    if(s < 0) ans--;

    writeln(ans);

}