/**
 * @author OZLIINEX
 * @brief P1223 排队接水
 * @date 2023-03-28
 */

#include "header.hpp"
#define MAXN 500001

struct Node
{
    int id, val;
    bool operator < (const Node &b) const {
        return val < b.val;
    }
};

int n;
Node a[MAXN];
ll ans;

void solve()
{
    n = read();
    req(i, 1, n) a[i].val = read(), a[i].id = i;
    sort(a + 1, a + n + 1);
    req(i, 1, n) writespace(a[i].id);
    req(i, 1, n) ans += (ll)(n - i) * a[i].val;
    // 后面排队的人等待的时间

    printf("\n%.2lf\n", double(ans) / n);


}