/**
 * @author OZLIINEX
 * @brief P3916 图的遍历
 * @date 2023-04-07
 */


// 反向遍历..没有很难啊!

#include "header.hpp"
#define MAXN 500001

struct Edge
{
    int to, next;
};

int n, m;
int ans[MAXN];
bool vis[MAXN];

int head[MAXN], cnt;
Edge edge[MAXN << 1];

void add_edge(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(int x, int num) // 当前数字，当前可抵达的最大点
{
    if(ans[x] > num) return;
    if(head[x] == -1) return;
    for(int i = head[x]; i != -1; i = edge[i].next)
    {
        int to = edge[i].to;
        if(vis[to]) continue;
        ans[to] = max(ans[to], max(num, x));
        vis[to] = true;
        dfs(to, max(num, x));
    }

    return;
}


void solve()
{
    int u, v;
    req(i, 0, MAXN - 1) head[i] = -1;
    req(i, 0, MAXN - 1) ans[i] = i;

    n = read(), m = read();
    req(i, 1, m)
    {
        int u = read(), v = read();
        add_edge(v, u);
    }

    for(int i = n; i > 0; i--) if(ans[i] == i) dfs(i, i);

    req(i, 1, n) printf("%d ", ans[i]);
}