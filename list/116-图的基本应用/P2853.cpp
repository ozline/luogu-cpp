/**
 * @author OZLIINEX
 * @brief P2853 [USACO06DEC]Cow Picnic S
 * @date 2023-05-02
 */

#include "header.hpp"
#define MAXN 1001

int k, n, m;
int a[MAXN]; // 第i个农场是否有奶牛
vector<int> adj[MAXN]; // 邻接表

int cnt[MAXN]; // 表示点i被遍历了多少次
bool vis[MAXN]; // 访问节点数
int ans;


void dfs(int x)
{
    vis[x] = true, cnt[x]++;

    if(adj[x].size() == 0) return;
    req(i, 0, adj[x].size() - 1)
    {
        int v = adj[x][i];
        if(!vis[v]) dfs(v);
    }
}

void solve()
{
    int u, v;
    cin >> k >> n >> m;
    req(i, 1, k) cin >> a[i];

    req(i, 1, m)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    req(i, 1, k)
    {
        req(j, 0, n) vis[j] = false;
        dfs(a[i]);
    }

    req(i, 1, n) if(cnt[i] == k) ans++;

    cout << ans << endl;
}