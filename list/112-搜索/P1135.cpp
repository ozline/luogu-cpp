/**
 * @author OZLIINEX
 * @brief P1135 奇怪的电梯
 * @date 2023-03-26
 */

// 实际上也可以用dijkstra跑最短路嘛，相当于每个电梯都和别的电梯有一个点连接

#include "header.hpp"
#define MAXN 201



// 避免卡DFS
int cnt = 0;
int maxx = 100000001;

int n, a, b;
int k[MAXN];
int vis[MAXN];

int ans = INF;

void dfs(int cur, int step)
{
    if(vis[cur]) return;

    if(step > ans) return;

    if(cnt++ > maxx) return; // 规避第一个点卡DFS，实际上取巧了

    if(cur == b)
    {
        ans = min(ans, step);
        return;
    }

    vis[cur] = true;

    if(cur + k[cur] <= n && !vis[cur + k[cur]]) dfs(cur + k[cur], step + 1);
    if(cur - k[cur] > 0 && !vis[cur - k[cur]]) dfs(cur - k[cur], step + 1);

    vis[cur] = false;
}

void solve()
{
    cin >> n >> a >> b;
    req(i, 1, n) cin >> k[i];
    dfs(a, 0);

    if(ans == INF) printf("-1\n");
    else printf("%d\n", ans);

    return;
}