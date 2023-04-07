/**
 * @author OZLIINEX
 * @brief P3916 图的遍历
 * @date 2023-04-07
 */


// 反向遍历..没有很难啊!

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
    int to, next;
};

int n, m;
int ans[MAXN];
bool vis[MAXN];

int head[MAXN], cnt;
Edge edge[MAXN << 1];

void add_edge(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(int x, int num) // 当前数字，当前可抵达的最大点
{
    if(ans[x] > num) return;
    if(head[x] == -1) return;
    for(int i = head[x]; i != -1; i = edge[i].next)
    {
        int to = edge[i].to;
        if(vis[to]) continue;
        ans[to] = max(ans[to], max(num, x));
        vis[to] = true;
        dfs(to, max(num, x));
    }

    return;
}


void solve()
{
    int u, v;
    req(i, 0, MAXN - 1) head[i] = -1;
    req(i, 0, MAXN - 1) ans[i] = i;

    n = read(), m = read();
    req(i, 1, m)
    {
        int u = read(), v = read();
        add_edge(v, u);
    }

    for(int i = n; i > 0; i--) if(ans[i] == i) dfs(i, i);

    req(i, 1, n) printf("%d ", ans[i]);
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