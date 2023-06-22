/**
 * @author OZLIINEX
 * @brief P4995 跳跳！
 * @date 2023-03-31
 */


// 写一波贪心思考
// 比如目前有 1 2 我们在地面， ->1->2还是->2->1呢
// 其实就是 1^2 + 2^2和3^2的比较
// 很明显，直接3^2更大
// 所以思路就是左右反复跳

#include "header.hpp"
#define MAXN 500001

ll n;
ll h[MAXN];

ll last = 0;
ll ans = 0;

void solve()
{
    n = read();
    req(i, 1, n) h[i] = read();
    sort(h + 1, h + 1 + n);
    req(i, 1, n)
    {
        if(i % 2)
        {
            ans += ll(pow(h[n + 1 - (i + 1) / 2] - last, 2));
            last = h[n + 1 - (i + 1) / 2];
        }
        else
        {
            ans += ll(pow(h[i / 2] - last, 2));
            last = h[i / 2];
        }
    }

    printf("%lld\n", ans);

    // 1: h[n] 2: h[1] 3: h[n - 1] 4: h[2]  5: h[n - 2]
}