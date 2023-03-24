/**
 * @author OZLIINEX
 * @brief P1605 迷宫
 * @date 2023-03-25
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

#define MAXN 101
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

struct Node {
    int x,y;
};

int n, m, t;
Node st, to;
int barrier[MAXN][MAXN];
bool vis[MAXN][MAXN];
int ans;

int pos_x[] = {0, 0, 1, -1};
int pos_y[] = {1, -1, 0, 0};


void dfs(int x, int y)
{
    vis[x][y] = true;

    if(x == to.x && y == to.y) {
        ans++;
        vis[x][y] = false;
        return;
    }

    req(i, 0, 3) {
        int nx = x + pos_x[i];
        int ny = y + pos_y[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(vis[nx][ny] || barrier[nx][ny]) continue;
        dfs(nx, ny);
    }

    vis[x][y] = false;
}


void solve()
{
    Node temp;
    cin >> n >> m >> t;
    cin >> st.x >> st.y >> to.x >> to.y;
    req(i, 1, t) cin >> temp.x >> temp.y, barrier[temp.x][temp.y] = 1;

    dfs(st.x, st.y);
    cout << ans;
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