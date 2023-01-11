/**
 * @author OZLIINEX
 * @brief P4779 单源最短路径模板 Dijkstra
 * @date 2022-07-10
 */

//使用优先队列优化+自定义结构体

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

#define MAXN 100001
#define INF 0x3f

using namespace std;

//边
struct Edge
{
    int next;
    int cost;
    Edge(int x,int y)
    {
        next = x;
        cost = y;
    }
};

//点
struct Node{
    int place, dist;
    bool operator<(const Node& t)const
    {
        return t.dist < dist;
    }

    Node(int o,int q)
    {
        place = o;
        dist = q;
    }
};

int n, m, s;  //n个点 m条有向边的带非负权图 起点为s

vector<Edge> edge[MAXN]; //first:下一个点 second:重量
bool vis[MAXN]; //表明这个点是否已访问过
int dis[MAXN]; //表明从起点到这个点的最短距离

void Dijkstra(int startNode)
{
    memset(vis, false, sizeof(vis));
    memset(dis, INF, sizeof(dis));

    priority_queue<Node> Q;
    dis[startNode] = 0;
    Q.push(Node(startNode,dis[startNode]));

    while (!Q.empty())
    {
        Node node = Q.top(); Q.pop(); //取点
        int place = node.place;
        if(vis[place]) continue; //访问过则跳过
        vis[place] = true;
        for (int i = 0; i < edge[place].size(); i++)
        {
            int next = edge[place][i].next;
            int heavy = edge[place][i].cost;
            if (dis[place] + heavy < dis[next])
            {
                dis[next] = dis[place]+ heavy;
                if(!vis[next])
                {
                    Q.push(Node(next,dis[next]));
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m,&s);
    for (int i = 0; i < m; i++)
    {
        int from,to,weight;
        scanf("%d %d %d", &from, &to, &weight);
        edge[from].push_back(Edge(to, weight));
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",dis[i]);
    }
    return 0;
}