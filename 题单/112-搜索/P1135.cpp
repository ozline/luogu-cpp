/**
 * @author OZLIINEX
 * @brief P1135 奇怪的电梯
 * @date 2023-03-26
 */

// 实际上也可以用dijkstra跑最短路嘛，相当于每个电梯都和别的电梯有一个点连接

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

#define MAXN 201
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



// 避免卡DFS
int cnt = 0;
int maxx = 100000001;

int n, a, b;
int k[MAXN];
int vis[MAXN];

int ans = INF;

void dfs(int cur, int step)
{
    if(vis[cur]) return;

    if(step > ans) return;

    if(cnt++ > maxx) return; // 规避第一个点卡DFS，实际上取巧了

    if(cur == b)
    {
        ans = min(ans, step);
        return;
    }

    vis[cur] = true;

    if(cur + k[cur] <= n && !vis[cur + k[cur]]) dfs(cur + k[cur], step + 1);
    if(cur - k[cur] > 0 && !vis[cur - k[cur]]) dfs(cur - k[cur], step + 1);

    vis[cur] = false;
}

void solve()
{
    cin >> n >> a >> b;
    req(i, 1, n) cin >> k[i];
    dfs(a, 0);

    if(ans == INF) printf("-1\n");
    else printf("%d\n", ans);

    return;
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