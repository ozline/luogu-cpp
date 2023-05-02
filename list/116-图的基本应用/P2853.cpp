/**
 * @author OZLIINEX
 * @brief P2853 [USACO06DEC]Cow Picnic S
 * @date 2023-05-02
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

int k, n, m;
int a[MAXN]; // 第i个农场是否有奶牛
vector<int> adj[MAXN]; // 邻接表

int cnt[MAXN]; // 表示点i被遍历了多少次
bool vis[MAXN]; // 访问节点数
int ans;


void dfs(int x)
{
    vis[x] = true, cnt[x]++;

    if(adj[x].size() == 0) return;
    req(i, 0, adj[x].size() - 1)
    {
        int v = adj[x][i];
        if(!vis[v]) dfs(v);
    }
}

void solve()
{
    int u, v;
    cin >> k >> n >> m;
    req(i, 1, k) cin >> a[i];

    req(i, 1, m)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    req(i, 1, k)
    {
        req(j, 0, n) vis[j] = false;
        dfs(a[i]);
    }

    req(i, 1, n) if(cnt[i] == k) ans++;

    cout << ans << endl;
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