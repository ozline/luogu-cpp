/**
 * @author OZLIINEX
 * @brief  P3811 【模板】乘法逆元
 * @date 2022-12-08
 */

/**
 * 1.欧拉定理
 * 如果a, p互质，那么a^(p-1) = 1 (mod p) 当p为质数时
 * 结合同余方程，可以知道 x == a^(p-2) (mod p) 求解即可
 *
 * 2.费马小定理
 * 如果p为质数，a与p互质，那么a^(p-1) = 1 (mod p)
 * 结合同余方程，可以知道 x == a^(p-2) (mod p) 求解即可
 *
 * 3.解不定方程
 * 解不定方程 ax == 1 (mod p) 等价于解不定方程 ax + py = 1
 * 可以用Exgcd求解
 * 由于p是质数，那么gcd(a, p) = 1;
 * 也就是求解不定方程 ax + by = gcd(a, b)
 *
 * 4.推导
 * https://www.luogu.com.cn/blog/user49618/solution-p3811
 */

#include "header.hpp"
#define MAXN 4000001

int x, y;
void exgcd(ll a, ll b)
{
    if(!b){ x = 1, y = 0; return; }
    exgcd(b, a % b);
    int t = x;
    x = y, y = t - a / b * y;
}

ll quick_power(ll a, ll b, ll p)
{
    ll ans = 1, base = a % p;
    while(b)
    {
        if(b & 1) ans *= base, ans %= p;
        base *= base;
        base %= p;
        b >>= 1;
    }
    return ans;
}

int n, p;

ll inv[MAXN] = {0, 1};

void solve()
{
    n = read(), p = read();
    // req(i, 1, n) writeln(quick_power(i, p - 2, p)); //解法1和2
    // req(i, 1, n) //解法3
    // {
    //     exgcd(i, p);
    //     writeln((x % p + p) % p);
    // }

    puts("1");
    for(int i = 2; i <= n; i++)
    {
        inv[i] = (ll)p - (p / i) * inv[p % i] % p;
        printf("%lld\n", inv[i]);
    }
    return;
}