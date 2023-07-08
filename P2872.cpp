/**
 * @author OZLIINEX
 * @brief P2872 [USACO07DEC]Building Roads S
 * @date 2023-04-12
 */

#include "header.hpp"
#define MAXN 1001

struct DisjoinSet
{
    int fa[MAXN];

    void init()
    {
        req(i, 1, MAXN - 1) fa[i] = i;
    }

    int find(int x)
    {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    void merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if(fx != fy) fa[fx] = fy;
    }
};


struct Node
{
    int x, y;

    bool operator<(const Node &obj) const {
        return (x * y) < (obj.x * obj.y);
    }

    double caldis(const Node &obj) const {
        return sqrt(pow(x - obj.x, 2) + pow(y - obj.y, 2));
    }
};

struct Edge
{
    int u, v;
    double dis;

    bool operator<(const Edge &obj) const {
        return dis < obj.dis;
    }
};


int n, m, cnt;
DisjoinSet s;
Edge edge[MAXN * MAXN];
Node node[MAXN];


double dis[MAXN][MAXN];
double ans;

void solve()
{
    int u, v;
    s.init();
    cin >> n >> m;
    req(i, 1, n) cin >> node[i].x >> node[i].y;

    // 计算距离
    req(i, 1, n) req(j, i + 1, n) dis[i][j] = dis[j][i] = node[i].caldis(node[j]);
    req(i, 1, m)
    {
        cin >> u >> v;
        dis[u][v] = dis[v][u] = 0;
    }

    req(i, 1, n) req(j, i + 1, m)
    {
        edge[++cnt].u = i;
        edge[cnt].v = j;
        edge[cnt].dis = dis[i][j];
    }

    sort(edge + 1, edge + 1 + cnt);

    req(i, 1, cnt)
    {
        u = edge[i].u, v = edge[i].v;
        if(s.find(u) != s.find(v))
        {
            s.merge(u, v);
            ans += edge[i].dis;
        }
    }

    printf("%.2lf", ans);
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    // fastio();
    solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}
