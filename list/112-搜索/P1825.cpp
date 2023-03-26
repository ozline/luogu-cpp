/**
 * @author OZLIINEX
 * @brief P1825 [USACO11OPEN]Corn Maze S
 * @date 2023-03-26
 */

// dfs改成bfs就过了

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

#define MAXN 401
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

struct Portal {
    int x1, y1;
    int x2, y2;
};

struct Node {
    int x, y, sum;

    Node(int a, int b, int c):x(a),y(b),sum(c){};
    Node():x(0),y(0),sum(0){};
};

int n, m, ans = INF;
char a[MAXN][MAXN]; // 地图
Portal p[101];      // 传送门
int sx, sy;         // 起点
int px[] = {0, 0, 1, -1};
int py[] = {1, -1, 0, 0};
bool vis[MAXN][MAXN];

queue<Node> q;

void add_portal(int x, int y, int w)
{
    if(p[w].x1) { p[w].x2 = x, p[w].y2 = y; }
    else { p[w].x1 = x, p[w].y1 = y; }
}

void bfs(int x, int y)
{
    q.push(Node(x, y, 0));
    vis[x][y] = true;

    while(!q.empty())
    {
        Node now = q.front(); q.pop();

        if(a[now.x][now.y] == 3)
        {
            ans = min(ans, now.sum);
            return;
        }

        if(now.sum > ans) continue;

        req(i, 0, 3)
        {
            int xx = now.x + px[i], yy = now.y + py[i];

            if(xx > 0 && xx <=n && yy > 0 && yy <=m && a[xx][yy] != 1 && !vis[xx][yy])
            {
                vis[xx][yy] = true;

                if(a[xx][yy] > 3)
                {
                    Portal ne = p[a[xx][yy] - 4];
                    if(ne.x1 == xx && ne.y1 == yy) q.push(Node(ne.x2, ne.y2, now.sum + 1));
                    else q.push(Node(ne.x1, ne.y1, now.sum + 1));
                }
                else q.push(Node(xx, yy, now.sum + 1));
            }
        }
    }
}

void solve()
{
    char ch;
    cin >> n >> m;
    getchar();
    req(i, 1, n)
    {
        req(j, 1, m)
        {
            ch = getchar();
            if(ch == '#') a[i][j] = 1; // barrier
            if(isupper(ch)) add_portal(i, j, ch - 'A'), a[i][j] = 4 + ch - 'A'; // portal
            if(ch == '=') a[i][j] = 3; // exit
            if(ch == '@') sx = i, sy = j; // start
        }
        getchar();
    }

    bfs(sx, sy);

    printf("%d\n", ans);
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}