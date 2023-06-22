/**
 * @author OZLIINEX
 * @brief P1629
 * @date 2022-10-11
 */

/**
 * 如果集合里只有1，那么1出现了1吃
 * 如果集合为{1, 2}，那么所有子集为{1}, {2], {1, 2}, 1出现了2次，2出现了2次
 * 如果集合为{1, 2, 3}，那么所有子集为{1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}, 1出现了4次，2出现了4次，3出现了4次
 * 继续推下去可以发现集合中的每个数字出现的次数均为集合长度len的2^(len - 1)
 * 那么答案就出来啦

 * 可以巩固一下快速幂
 */

#include "header.hpp"
#define MAXN 1001

ll quick_power(ll a, ll b)
{
    ll ans = 1, base = a;
    while(b)
    {
        if(b & 1) ans *= base;
        base *= base;
        b >>=1;
    }
    return ans;
}

ll a[MAXN], cnt;
ll ans;

void solve()
{
    while(cin>>a[++cnt]);
    req(i, 1, cnt) ans += quick_power(2, cnt - 2)*a[i];
    printf("%lld", ans);

    return;
}