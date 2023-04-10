/**
 * @author OZLIINEX
 * @brief P1462 通往奥格瑞玛的道路
 * @date 2022-12-04
 */


/**
 * Dijkstra + 二分
 * 这道题的意思是，求一个开销，这个开销需要满足：
 * 1.这个人可以抵达终点
 * 2.在他经过的所有路径中，这个开销值是最大的
 * 3.在1和2的条件下的所有开销值中，我们需要求的开销值是最小的
 *
 * 这道题有血量和路费，我们使用血量作为最短路的dis值，路费作为二分的值
 * 我们跑一遍最短路，获取到终点所需要的最小血量，再和我们有的血量对比
 * 如果大于，那直接AFK了
 * 同时我们可以给最短路加上限制条件，比如dijkstra里有一句代码是
 * if(f[next] > top) continue; // f[i]表示城市i的开销，top则是参数
 * 我们给dijkstra传入一个top参，这个top参表示最大允许的单个城市开销值
 * 不断二分这个开销值，一直到如果小于这个值，那么我们无法走到终点
 *
 * 换句话说，我们以城市花费为依据，在去掉某些大额花费城市后，依然可以走得通
 * 我们需要求的就是我们最小需要保留哪些城市，这些城市中的最大开销
 *
 * 我这道题其实卡了好几个月，准确来说是一直没补
 * 然后集训队选拔赛上就考了这道题，很荣幸的g了
 *
 * 一开始我是用SPFA走的，但是不知道为什么SPFA会挂一部分点
 * 后来看了题解试着改成dijkstra，就过了
 *
 * emm，很玄学
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

#define MAXN 1000001
#define INF 0x3f3f3f3f
#define INFLL 1LL<<60
#define writespace(a) write(a),putchar(' ')
#define writeln(a) write(a),putchar('\n')
#define req(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define fastio() std::ios::sync_with_stdio(false), std::cin.tie(0)

#ifdef DEBUG
    #define debug(...) fprintf(stdout,__VA_ARGS__)
    #define debugvar(a) cout<<"[DEBUG] "#a" = "<<a<<endl
#else
    #define debug(...) fun()
    #define debugvar(a) fun()
    void fun() { return; }
#endif

typedef long long ll;
using namespace std;


inline int read() {
    int x = 0, w = 1; char ch = 0;
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return (x*w);
}

inline void write(int x) {
    if(x<0) putchar('-'), x = -x;
    static int sta[35]; int top = 0;
    while(x) {sta[top++] = x % 10, x /= 10;}
    while (top) putchar(sta[--top] + 48);
}
/* END OF TEMPLATE */

struct Edge
{
    int to;
    int next;
    ll w;
};

struct Node
{
    int node;
    int dist;

    bool operator < (const Node &obj) const
    {
        return dist > obj.dist;
    }

    Node(int a, int b):node(a),dist(b){};
};

Edge edge[MAXN*2];
int head[MAXN], cnt;

ll dis[MAXN*2], vis[MAXN];

int i, j;
int n, m, b; // 点 边 出发血量
ll f[MAXN], u[MAXN]; // 收费情况 后续二分

void add_edge(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

bool SPFA(ll top)
{
    if(f[1] > top || f[n] > top) return false;

    req(i,0,n) dis[i] = INFLL, vis[i] = 0;
    priority_queue<Node> Q;
    dis[1] = 0, Q.push(Node(1,0));

    while(!Q.empty())
    {
        Node node = Q.top(); Q.pop();

        int now = node.node;

        // vis[now] = true;

        for(int i = head[now]; ~i; i = edge[i].next)
        {
            int next = edge[i].to;

            if(dis[now] + edge[i].w < dis[next])
            {
                dis[next] = dis[now] + edge[i].w;
                if(f[next] > top) continue;
                if(!vis[next]) Q.push(Node(next, dis[next])), vis[next] = true;
            }
        }
    }

    return (dis[n] <= b);
}

void solve()
{
    req(i,0,MAXN-1) head[i] = -1;

    scanf("%d %d %d", &n, &m, &b);

    req(i,1,n) scanf("%lld", &f[i]), u[i] = f[i];

    req(i,1,m)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    if(SPFA( INFLL ))
    {
        sort(u + 1, u + 1 + n);
        int l = 1, r = n, mid, ans = 0;
        while(l <= r)
        {
            mid = (l + r) >> 1;

            if(SPFA(u[ mid ])) ans = u[mid], r = mid - 1;
            else l = mid + 1;
        }

        printf("%d",ans);
    }
    else printf("AFK\n");
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    fastio(); solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}