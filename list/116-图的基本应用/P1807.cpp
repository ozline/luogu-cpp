/**
 * @author OZLIINEX
 * @brief P1807 最长路
 * @date 2023-04-10
 */


// 样例没错，结果我忘记更新我本地的样例了
// 我本地弄了一个环出来，草

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

#define MAXN 500001
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