/**
 * @author OZLIINEX
 * @brief P1629 邮递员送信
 * @date 2022-12-3
 */


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <ctime>
#include <stack>
#include <unordered_map>

// #define DEBUG

/**
 * 题意大约是我们需要求地图上1和任意点之间往返的最短路，比如1->2和2->1
 * 这里我第一次做的时候思考的是跑一遍dijkstra，然后*2就行了
 * 但是这道题是一个单向边，不是双边，所以这样做是不对的
 *
 * 这时候我们就可以考虑到，我们需要求2个最短路，一个是过去的，一个是回来的
 * 这时候容易想到Floyd，但是注意数据范围，10^4，这个还是不行
 *
 * 实际上，我们可以考虑建立反图，也就是说，本来有一条边是1->2，我们反着来，建立2->1的
 * 这样子，原来2->1的路就会变成1->2，我们可以在这个反图上求1出发的最短路
 *
 * 我们可以思考一下这个思路的正确性
 *
 * 接下来，怎么存这个反图？
 * 我一开始用的是建两个图，一个正图，一个反图
 * 后来查看题解，发现可以直接在原图上建立反图，比如我们一共有n个点，那么我们建立反图时，加入第i个点可以表示为n+i
 * 在跑dijkstra时，并不会跑到反图上！因为没有任何一个边连接了第一个图和第二个图
 *
 * 这样子就节省了很大的空间
*/

#include "header.hpp"
#define MAXN 3000001

struct Edge
{
    int v, next, w;
};

struct Node
{
    int place, dist;

    Node(int a, int b):place(a),dist(b){};

    bool operator<(const Node &obj) const
    {
        return obj.dist < dist;
    }
};


int i,j;

Edge edge[MAXN];
int head[MAXN], cnt;
ll dis[MAXN], vis[MAXN];
priority_queue<Node> Q;

int n, m;
int ans;

void add_edge(int u, int v, int w)
{
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;

    // 同时建一个反图
    edge[cnt].v = u + n;
    edge[cnt].w = w;
    edge[cnt].next = head[v + n];
    head[v + n] = cnt++;
}

void dijkstra(int start)
{
    dis[start] = 0;
    Q.push(Node(start, 0));
    while (!Q.empty())
    {
        Node now = Q.top();
        Q.pop();
        if (vis[now.place]) continue;
        vis[now.place] = 1;
        for (int i = head[now.place]; ~i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (dis[v] > dis[now.place] + edge[i].w)
            {
                dis[v] = dis[now.place] + edge[i].w;
                if(!vis[v]) Q.push(Node(v, dis[v]));
            }
        }
    }
}

void solve()
{
    for(int i=0;i<MAXN;i++) head[i] = -1;

    // n = read(), m = read();
    scanf("%d %d",&n,&m);
    req(i,1,m)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        // add_edge(read(), read(), read());
        add_edge(u,v,w);
    }

    for(int i=0;i<MAXN;i++) vis[i] = false, dis[i] = INF;

    dijkstra(1);

    req(i, 2, n) ans += dis[i];

    dijkstra(1 + n);

    req(i, n + 2, n*2) ans += dis[i];

    write(ans);


    return;
}