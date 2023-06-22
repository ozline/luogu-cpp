/**
 * @author OZLIINEX
 * @brief P1678 烦恼的高考志愿
 * @date 2023-03-27
 */


// d了半天，发现是局部变量和全局变量重名了，我****

#include "header.hpp"
#define MAXN 100001

int m, n;
int a[MAXN], b[MAXN];

ll ans;

void solve()
{
    ll l, r, mid, tmp;
    m = read(), n = read();
    req(i, 1, m) a[i] = read(); // 学校
    req(i, 1, n) b[i] = read(); // 学生

    sort(a + 1, a + m + 1);
    sort(b + 1, b + n + 1);

    l = 1;

    // 我们忽略了只有一个的情况..
    if(m == 1)
    {
        req(i, 1, n) ans += abs(a[1] - b[i]);
        printf("%lld\n", ans);
        return;
    }

    req(i, 1, n)
    {
        r = m + 1;

        // 二分找第一个不大于 b[i] 的数的下标
        while(l < r)
        {
            mid = (l + r) >> 1;
            if (a[mid] <= b[i]) l = mid + 1;
            else r = mid;
        }
        if(abs(a[l] - b[i]) < abs(a[l - 1] - b[i])) tmp = abs(a[l] - b[i]);
        else
        {
            tmp = abs(a[l - 1] - b[i]);
            l--;
        }

        // 修复上述漏洞：a[0]我们是没有定义的
        if(l == 0) ans += a[1] - b[i], l = 1;
        else ans += tmp;
    }

    printf("%lld\n", ans);

    return;
}