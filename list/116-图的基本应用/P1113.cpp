/**
 * @author OZLIINEX
 * @brief P1113 杂务
 * @date 2023-04-07
 */

#include "header.hpp"
#define MAXN 500001
/* END OF TEMPLATE */

struct Node { int to, next; };

int head[MAXN], cnt;
Node edge[MAXN << 4];

void add_edge(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int n;
int in[MAXN], ans[MAXN], a[MAXN];
queue<int> q;

void solve()
{
    req(i, 1, MAXN - 1) head[i] = -1;
    int nums, pre;
    scanf("%d", &n);
    req(i, 1, n)
    {
        scanf("%d%d", &nums, &a[i]);
        while(1)
        {
            scanf("%d", &pre);
            if(pre == 0) break;
            add_edge(pre, nums);
            in[nums]++;
        }
    }

    req(i, 1, n) if(in[i] == 0) q.push(i), ans[i] = a[i];

    while(!q.empty())
    {
        int now = q.front(); q.pop();

        for(int i = head[now]; i != -1; i = edge[i].next)
        {
            int to = edge[i].to;
            if(--in[to] == 0) q.push(to);
            ans[to] = max(ans[to], ans[now] + a[to]);
        }
    }

    int tmp = 0;
    req(i, 1, n) tmp = max(tmp, ans[i]);

    printf("%d\n", tmp);
}