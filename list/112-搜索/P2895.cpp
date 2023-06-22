/**
 * @author OZLIINEX
 * @brief P2895 [USACO08FEB]Meteor Shower S
 * @date 2023-03-26
 */

// cnm, 输入写错了，d了半天，wrnm

#include "header.hpp"
#define MAXN 50001

struct Node {
    int x, y, t;

    Node(int a, int b, int c):x(a),y(b),t(c){};
};

int m;
int me[MAXN]; // meteors
int a[406][406];
bool vis[406][406];
int ans = INF;
queue<Node> q;

int pos_x[] = {0, 0, 1, -1};
int pos_y[] = {1, -1, 0, 0};

void add_meteors(int x, int y, int t)
{
    if(a[x][y] > t) a[x][y] = t;

    req(i, 0, 3)
    {
        int xx = x + pos_x[i], yy = y + pos_y[i];

        if(xx >= 0 && yy >= 0 && a[xx][yy] > t) a[xx][yy] = t;
    }
}

void bfs()
{
    if(a[0][0] == 0) return;

    q.push(Node(0, 0, 0));
    vis[0][0] = true;

    while(!q.empty())
    {
        Node now = q.front(); q.pop();
        // debug("x: %d, y: %d, t: %d\n", now.x, now.y, now.t);

        if(a[now.x][now.y] == INF && (now.x != 0 || now.y != 0))
        {
            // debug("x: %d y: %d\n", now.x, now.y);
            ans = min(ans, now.t);

            continue;
        }
        else if(now.t > ans) return;

        req(i, 0, 3)
        {
            int xx = now.x + pos_x[i], yy = now.y + pos_y[i];

            if(xx >= 0 && yy >= 0 && xx < 405 && yy < 405 && a[xx][yy] > now.t + 1 && !vis[xx][yy])
            {
                // debug("xx : %d yy: %d\n", xx, yy);
                vis[xx][yy] = true;
                q.push(Node(xx, yy, now.t + 1));
            }
        }
    }
}

void solve()
{
    int t1, t2, t3;
    cin >> m;
    req(i, 0, 405) req(j, 0, 405) a[i][j] = INF; // init

    req(i, 1, m)
    {
        cin >> t1 >> t2 >> t3;
        add_meteors(t1, t2, t3);
    }

    // req(i, 1, 10)
    // {
    //     req(j, 1, 10) putchar(a[i][j] + 48);
    //     putchar('\n');
    // }

    bfs();
    printf("%d\n", ans == INF ? -1 : ans);
    return;
}