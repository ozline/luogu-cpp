/**
 * @author OZLIINEX
 * @brief P1536 村村通
 * @date 2023-01-23
 */

// 并查集

#include "header.hpp"
#define MAXN 1001

int father[MAXN];

void set_init()
{
    req(i, 0, MAXN - 1) father[i] = i;
}

int set_find(int x)
{
    if(father[x] == x) return x;
    return father[x] = set_find(father[x]);
}

void set_union(int x, int y)
{
    int fx = set_find(x);
    int fy = set_find(y);
    if(fx != fy) father[fx] = fy;
}

int n, m;
bool vis[MAXN];
int ans;

void solve()
{
    int a, b;
    while(1)
    {
        n = read();
        if(n == 0) break;
        m = read(), ans = 0;
        set_init();
        req(i, 1, MAXN - 1) vis[i] = false;
        req(i, 1, m) set_union(read(), read());
        req(i, 1, n) if(father[i] == i) ans++;
        printf("%d\n", ans - 1);
    }
    return;
}