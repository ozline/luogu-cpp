/**
 * @author OZLIINEX
 * @brief P3817 小A的糖果
 * @date 2023-03-29
 */

#include "header.hpp"
#define MAXN 500001


ll n, x;
ll a[MAXN];
ll ans;

void solve()
{
    n = read(), x = read();
    req(i, 1, n) a[i] = read();

    // sort(a + 1, a + 1 + n);

    req(i, 2, n)
    {
        if(a[i] + a[i - 1] > x) ans += a[i] + a[i - 1] - x, a[i] = x - a[i - 1];
    }

    printf("%lld\n", ans);
}