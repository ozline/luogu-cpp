/**
 * @author OZLIINEX
 * @brief P1144 最短路计数 SPFA
 * @date 2022-07-15
 */

//Ref: https://www.cnblogs.com/luoshui-tianyi/p/11644633.html

/*

跑完SPFA后，我们可以知道从出发点抵达各个点的最短距离是多少

这时候我们可以开始计算答案

假设当前需要判断的点为x

我们设一个数组ans[MAXN]

其中ans[x]表示从出发点到点x的最短路的数量

我们遍历一遍各个点，假设当前遍历点为i

如果dis[x] = dis[i] + 1，则说明从从1出发到i点的最短路，和从1出发到x点的最短路的差值为1

也就是说，从i点走到x点仅需一步，也就是dis(i,x) = 1;

那么如果我们知道了ans[i]，也就是从出发点到i点的最短路的数量

那么我们当前所求点x的ans[x] 不就等于 ans[x] + ans[i] 吗？

之所以是+=，是因为可能不止一个点i离点x的距离为1，需要把多个ans[i]累加

那么我们就更新ans[x]+=ans[i]

这时候我们会发现，我们可能不知道ans[i]的答案是多少

那就继续递归下去，算ans[i]->ans[i-1]->...->ans[1]，而ans[1]我们设答案为1（因为从出发点到出发点的不同最短路数就是1），然后回溯回去就好了

可以使用记忆化，这样不用重复计算多个ans[i]的答案

*/

#include "header.hpp"
#define MAXN 500001
#define MOD 100003



struct Edge
{
    int to;
    int next;
};


Edge edge[2*MAXN];
int head[MAXN];
int edge_count = 0;

void init()
{
    memset(head,-1,sizeof(head));
    edge_count = 0;
}

void addEdge(int u,int v)
{
    edge[edge_count].to = v;
    edge[edge_count].next = head[u];
    head[u] = edge_count++;
}

int dis[MAXN];
int ans[MAXN];

void SPFA(int start)
{
    queue<int> Q;
    memset(dis,INF,sizeof(dis));
    memset(ans,0,sizeof(ans));
    dis[start] = 0;
    ans[start] = 1;
    Q.push(start);

    while(!Q.empty())
    {
        int now = Q.front(); Q.pop();

        for(int i=head[now];i!=-1;i = edge[i].next)
        {
            int next = edge[i].to;
            if(dis[now] + 1 < dis[next])
            {
                dis[next] = dis[now] + 1;
                Q.push(next);
            }
        }
    }
}

int calculate_ans(int x)
{
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int next = edge[i].to;
        if(dis[next] + 1 == dis[x])
        {
            if(ans[next])
            {
                ans[x] += ans[next];
            }
            else
            {
                ans[x] += calculate_ans(next);
            }

            ans[x] %= MOD;

            //有可能ans[next]这个点还没算过，那我们就递归去算一下
        }
    }

    return ans[x];
}

int n,m;

void solve()
{
    init();

    cin>>n>>m;

    while(m--)
    {
        int x,y;
        cin>>x>>y;
        addEdge(x,y);
        addEdge(y,x);
    }

    SPFA(1);

    for(int i=1;i<=n;i++)
    {
        cout<<(ans[i]>0? ans[i]:calculate_ans(i))<<endl;
    }
}