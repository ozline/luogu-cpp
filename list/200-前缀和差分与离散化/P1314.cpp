/**
 * @file P1314.cpp
 * @author ozlinex
 * @brief P1314 [NOIP2011 提高组] 聪明的质监员
 * @date 2023-07-10
 */


// 首先，注意数据范围，s < 10^12，而template中的快读是适用于int的
// 因此除了更改快读外，我们也可以直接改为cin，不会T的

// 然后说一下思路吧
// 这道题是一个很明显的二分答案，我只知道需要二分这个W，但是不知道应该如何二分
// 这个W应该如何分呢？
// 我们可以发现，w越大，那么实际上我们计算出来的y越小，因为满足条件的矿石越来越少了
// 那么我们设置左边界为0（或者最小矿石数量），右边界为最大的矿石数量（此时y = 0）

// 然后在计算的过程中，我们枚举这个w，然后做前缀和操作，这样可以把O(n^2)的时间化简为O(2 * n)的时间

// 其他就没啥难度了，主要是太久没做题了..

#include "header.hpp"
#define MAXN 500001

ll n, m, s;
ll w[MAXN], v[MAXN], minx = INF, maxx = 0;
ll l[MAXN], r[MAXN];

ll ans = INFLL, sum;
ll pre_n[MAXN], pre_v[MAXN];

bool check(int x)
{
    sum = 0;
    ll tmp = 0;
    req(i, 0, MAXN - 1) pre_v[i] = 0, pre_n[i] = 0;

    req(i, 1, n)
    {
        if(w[i] >= x) pre_n[i] = pre_n[i - 1] + 1, pre_v[i] = pre_v[i - 1] + v[i];
        else pre_n[i] = pre_n[i - 1], pre_v[i] = pre_v[i - 1];
    }

    req(i, 1, m)
    {
        tmp += (pre_n[r[i]] - pre_n[l[i] - 1]) * (pre_v[r[i]] - pre_v[l[i] - 1]);
    }

    sum = llabs(tmp - s);
    return tmp > s;
}

void solve()
{
    cin >> n >> m >> s;
    req(i, 1, n)
    {
        cin >> w[i] >> v[i];
        minx = min(minx, w[i]);
        maxx = max(maxx, w[i]);
    }
    req(i, 1, m) cin >> l[i] >> r[i];

    ll left = minx - 1, right = maxx, mid;
    while(left <= right)
    {
        ll mid = (left + right) >> 1;
        if(check(mid)) left = mid + 1;
        else right = mid - 1;
        ans = min(ans, sum);
    }

    printf("%lld\n", ans);
}