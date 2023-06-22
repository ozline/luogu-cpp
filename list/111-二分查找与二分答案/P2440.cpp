/**
 * @author OZLIINEX
 * @brief P2440 木材加工
 * @date 2023-03-27
 */


// 第一次拿了76，WA两个点，看了一下答案，好家伙
// 比如你有n段，其中n - 1个都很短，最后一个很长
// 那么你可以直接放弃那n - 1个，只从第n个跑..
// 把代码中的r = min(r, a[i]) 改成 r = max(r, a[i]) 就过了
// 草!

#include "header.hpp"
#define MAXN 200001

ll n, k;
int a[MAXN];

int l = 0, r = INF;

ll cal(int x)
{
    int res = 0;
    req(i, 1, n) res += a[i] / x;
    return res;
}

void solve()
{
    n = read(), k = read();
    req(i, 1, n) a[i] = read(), r = max(r, a[i]);

    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(cal(mid) >= k) l = mid;
        else r = mid - 1;
    }
    writeln(l);
}