/**
 * @author OZLIINEX
 * @brief P5318 【深基18.例3】查找文献
 * @date 2023-04-07
 */

// 简单的对图的搜索

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

#define MAXN 101001
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

int n, m;

vector<int> a[MAXN];
bool vis[MAXN];

void dfs(int x)
{
    vis[x] = true;
    printf("%d ", x);
    if(!a[x].size()) return;
    req(i, 0, a[x].size() - 1) if(! vis[a[x][i]] ) dfs(a[x][i]);
}


queue<int> q;
void bfs(int x)
{
    while(!q.empty()) q.pop();
    req(i, 0, MAXN - 1) vis[i] = false;

    q.push(x);

    while(!q.empty())
    {
        int now = q.front(); q.pop();

        if(vis[now]) continue;
        vis[now] = true;

        printf("%d ", now);
        if(!a[now].size()) continue;

        req(i, 0, a[now].size() - 1)
        {
            if(!vis[ a[now][i] ]) q.push(a[now][i]);
        }
    }
}

void solve()
{
    int x, y;
    n = read(), m = read();
    while(m--)
    {
        x = read(), y = read();
        a[x].push_back(y);
    }

    // 排序
    req(i, 1, n) sort(a[i].begin(), a[i].end());

    dfs(1);
    putchar('\n');
    bfs(1);
    putchar('\n');
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