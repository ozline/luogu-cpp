/**
 * @author OZLIINEX
 * @brief P5638 【CSGRound2】光骓者的荣耀
 * @date 2022-12-05
 */

/*
    ..太简单了
*/
#include "header.hpp"
#define MAXN 2000001

ll n, k;
ll a[MAXN], prefix[MAXN];
ll discount;

void solve()
{
    scanf("%lld %lld",&n, &k);
    req(i, 1, n)
    {
        scanf("%lld", &a[i]);
        prefix[i] = prefix[i - 1] + a[i];
        // if(i == 1) prefix[1] = a[i], discount = prefix[1];
        if(i >= k) discount = max(discount, prefix[i] - prefix[i - k]);
        // 此处要更改为i >= k 而不是 i > k, 否则会漏掉从1开始的跳跃
        else discount = max(discount, prefix[i] - prefix[1]);
    }

    printf("%lld", prefix[n] - discount);

    return;
}