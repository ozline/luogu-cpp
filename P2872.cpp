/**
 * @author OZLIINEX
 * @brief P2872 [USACO07DEC]Building Roads S
 * @date 2023-04-12
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

#define MAXN 1001
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
typedef unsigned long long ull;
using namespace std;


inline int read() {
    int x = 0, w = 1; char ch = 0;
    while(ch < '0' || ch > '9') { if(ch == '-') w = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return(x * w);
}

inline void write(int x) {
    if(x == 0) { putchar('0'); return; }
    static int sta[35]; int top = 0;
    if(x<0) putchar('-'), x = -x;
    while(x) { sta[top++] = x % 10, x /= 10; }
    while(top) putchar(sta[--top] + 48);
}
/* END OF TEMPLATE */

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
