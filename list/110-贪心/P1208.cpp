/**
 * @author OZLIINEX
 * @brief P1208 [USACO1.3]混合牛奶 Mixing Milk
 * @date 2023-03-29
 */

#include "header.hpp"
#define MAXN 500001

struct Node
{
    int a, b; // a: price, b: amount

    bool operator<(const Node &rhs) const
    {
        return a < rhs.a;
    }
};

int n, m;
Node a[5001];
int ans;


void solve()
{
    n = read(), m = read();
    req(i, 1, m) scanf("%d %d", &a[i].a, &a[i].b);
    sort(a + 1, a + 1 + m);

    req(i, 1, m)
    {
        if(n <= a[i].b)
        {
            ans += n * a[i].a;
            break;
        }
        else
        {
            ans += a[i].a * a[i].b;
            n -= a[i].b;
        }
    }

    printf("%d", ans);
}