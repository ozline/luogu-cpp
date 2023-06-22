/**
 * @author OZLIINEX
 * @brief P1807 最长路
 * @date 2023-04-10
 */


// 样例没错，结果我忘记更新我本地的样例了
// 我本地弄了一个环出来，草

#include "header.hpp"
#define MAXN 500001

struct Edge
{
    int to, next, w;
};

struct Node
{
    int u, w;

    bool operator<(const Node &obj) const {
        return w < obj.w;
    }

    Node(int a, int b):u(a),w(b){};
    Node():u(0),w(0){};
};


int n, m;
int head[MAXN], cnt;
Edge edge[MAXN << 1];
queue<Node> q;
int vis[MAXN], dis[MAXN];

void add_edge(int u, int v, int w)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}


void SPFA(int x)
{
    dis[x] = 0;
    q.push(Node(x, 0));
    vis[x] = true;

    while(!q.empty())
    {
        debugvar(q.size());
        Node now = q.front(); q.pop();
        int u = now.u;

        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if(dis[v] < dis[u] + edge[i].w)
            {
                dis[v] = dis[u] + edge[i].w;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(Node(v, dis[v]));
                }
            }
        }
    }
}

void solve()
{
    int u, v, w;
    scanf("%d%d", &n, &m);

    req(i, 0, MAXN - 1) dis[i] = -1, head[i] = -1;
    req(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }

    SPFA(1);
    printf("%d\n", dis[n]);


}