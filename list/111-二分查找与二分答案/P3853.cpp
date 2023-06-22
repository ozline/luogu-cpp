/**
 * @author OZLIINEX
 * @brief P3853 [TJOI2007]路标设置
 * @date 2023-03-28
 */

// 因为先做了1182，所以这到题起手就是80分
// 然后卡在了2# 10# 和Subtask 1#
// 先说附加测试点，这个测试点是测试check函数中的参数x的，如果这个x==0，那么我们是不能直接除的
// 很明显，如果x==0，cnt=∞，我们直接返回false
// 接下来是2#和10# 这两个测试点也是测试check函数中的除法的
// 考虑两个路灯分别在60、90，此时x=10，我们主观角度上会发现应该插入2个路灯
// 但是我们的算法是(a[i] - a[i - 1]) / x，答案是3，我们应该改成(a[i] - a[i - 1] - 1)


#include "header.hpp"
#define MAXN 200001

ll l, n, k;
ll a[MAXN];

bool check(ll x)
{
    if(x == 0) return false;
    ll cnt = 0;
    req(i, 1, n)
    {
        if(a[i] - a[i - 1] > x) cnt += (a[i] - a[i - 1] - 1) / x;
    }
    if(l - a[n] > x) cnt += (l - a[n] - 1) / x;
    return cnt <= k;
}

void solve()
{
    ll le = 1, r = l, ans = 0, mid, tmp;
    l = read(), n = read(), k = read();
    req(i, 1, n) a[i] = read();
    while(le <= r)
    {
        mid = (le + r) >> 1;
        if(check(mid)) r = mid - 1;
        else le = mid + 1;
    }

    printf("%lld\n", le);
}