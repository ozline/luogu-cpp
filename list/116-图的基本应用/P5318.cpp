/**
 * @author OZLIINEX
 * @brief P5318 【深基18.例3】查找文献
 * @date 2023-04-07
 */

// 简单的对图的搜索

#include "header.hpp"
#define MAXN 101001

int n, m;

vector<int> a[MAXN];
bool vis[MAXN];

void dfs(int x)
{
    vis[x] = true;
    printf("%d ", x);
    if(!a[x].size()) return;
    req(i, 0, a[x].size() - 1) if(! vis[a[x][i]] ) dfs(a[x][i]);
}


queue<int> q;
void bfs(int x)
{
    while(!q.empty()) q.pop();
    req(i, 0, MAXN - 1) vis[i] = false;

    q.push(x);

    while(!q.empty())
    {
        int now = q.front(); q.pop();

        if(vis[now]) continue;
        vis[now] = true;

        printf("%d ", now);
        if(!a[now].size()) continue;

        req(i, 0, a[now].size() - 1)
        {
            if(!vis[ a[now][i] ]) q.push(a[now][i]);
        }
    }
}

void solve()
{
    int x, y;
    n = read(), m = read();
    while(m--)
    {
        x = read(), y = read();
        a[x].push_back(y);
    }

    // 排序
    req(i, 1, n) sort(a[i].begin(), a[i].end());

    dfs(1);
    putchar('\n');
    bfs(1);
    putchar('\n');
}