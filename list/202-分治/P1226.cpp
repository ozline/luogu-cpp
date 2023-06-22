/**
 * @author OZLIINEX
 * @brief P226 【模板】快速幂||取余运算
 * @date 2022-12-08
 */

#include "header.hpp"
#define MAXN 500001

ll quick_power(ll a, ll b, ll p)
{
    ll ans = 1, base = a;
    while(b)
    {
        if(b & 1) ans *= base, ans %= p;
        base *= base;
        base %= p;
        b >>= 1;
    }
    return ans;
}

// 如果要不取余的话，去掉里面对p的mod就行了

void solve()
{
    ll a, b, p;
    scanf("%lld %lld %lld",&a, &b, &p);
    printf("%lld^%lld mod %lld=%lld", a, b, p, quick_power(a, b, p));
    return;
}