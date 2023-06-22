/**
 * @author OZLIINEX
 * @brief P1551 亲戚
 * @date 2023-01-22
 */

// 并查集模板
#include "header.hpp"
#define MAXN 5001

int fa[MAXN];

void set_init()
{
    req(i, 0, MAXN - 1) fa[i] = i;
}

int set_find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = set_find(fa[x]);
}

void set_union(int x, int y)
{
    int fx = set_find(x);
    int fy = set_find(y);

    if(fx != fy) fa[fy] = fx;
}

int n, m, p;

void solve()
{
    set_init();

    n = read(), m = read(), p = read();

    req(i, 1, m)
    {
        int x = read(), y = read();
        set_union(x, y);
    }

    while(p--)
    {
        int a = read(), b = read();
        puts((set_find(a) != set_find(b)) ? "No" : "Yes");
    }


    return;
}