/**
 * @author OZLIINEX
 * @brief P1605 迷宫
 * @date 2023-03-25
 */


#include "header.hpp"
#define MAXN 101

struct Node {
    int x,y;
};

int n, m, t;
Node st, to;
int barrier[MAXN][MAXN];
bool vis[MAXN][MAXN];
int ans;

int pos_x[] = {0, 0, 1, -1};
int pos_y[] = {1, -1, 0, 0};


void dfs(int x, int y)
{
    vis[x][y] = true;

    if(x == to.x && y == to.y) {
        ans++;
        vis[x][y] = false;
        return;
    }

    req(i, 0, 3) {
        int nx = x + pos_x[i];
        int ny = y + pos_y[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(vis[nx][ny] || barrier[nx][ny]) continue;
        dfs(nx, ny);
    }

    vis[x][y] = false;
}


void solve()
{
    Node temp;
    cin >> n >> m >> t;
    cin >> st.x >> st.y >> to.x >> to.y;
    req(i, 1, t) cin >> temp.x >> temp.y, barrier[temp.x][temp.y] = 1;

    dfs(st.x, st.y);
    cout << ans;
    return;
}