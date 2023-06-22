/**
 * @author OZLIINEX
 * @brief P1873 [COCI 2011/2012 #5] EKO / 砍树
 * @date 2023-03-27
 */

#include "header.hpp"
#define MAXN 1000001

int n, m;
int a[MAXN];
int idx;
int ans;

void solve()
{
    cin >> n >> m;
    req(i,1,n) cin >> a[i];

    sort(a + 1,a + n + 1,greater<int>());

    for(idx = 2; idx <= n; idx++)
     {
        m -= (a[idx - 1] - a[idx]) * (idx - 1);
        if(m <= 0) break;
    }

    ans = a[idx] - m / (idx - 1);

    // 这个 - m / (idx - 1) 实际上是加法，我们可以注意到上面那个for循环的最后一次迭代
    // m是有可能小于0的，例如下面这个情况： 20 19 18 10，我们希望拿到10m的木棍，按照上述算法
    // 我们最后一次裁剪将会直接剪到10，实际上我们不需要裁这么多
    // 这个就是给他加回去，让多出来的m平摊到每一颗已经裁剪过的树上，如果平摊不了的话，意味着
    // 就只能多裁这么多，这也利用了整数除法抹小数点的性质


    cout << ans;

    // 20 19 18 17 16 15

    return;
}