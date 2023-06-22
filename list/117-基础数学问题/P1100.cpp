/**
 * @author OZLIINEX
 * @brief P1100 高低位交换
 * @date 2023-04-10
 */

#include "header.hpp"
#define MAXN 500001


ll n;
int a[MAXN], cnt, suffix;
ll tmp;


ll quick_power(int a, int b)
{
    ll ans = 1, base = a;
    while(b)
    {
        if(b & 1) ans *= base;
        base = base * base;
        b >>= 1;
    }

    return ans;
}

void solve()
{
    cin >> n;

    while(n) { a[32 - cnt++] = n % 2; n /= 2; }
    req(i, 1, 16) swap(a[i], a[16 + i]);

    req(i, 1, 32) tmp += a[i] * quick_power(2, 32 - i);

    printf("%lld\n", tmp);

}