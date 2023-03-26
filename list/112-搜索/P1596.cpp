/**
 * @author OZLIINEX
 * @brief P1596 [USACO10OCT]Lake Counting S
 * @date 2023-03-26
 */

// 还是忘记了，cin后如果有换行，同时新的行要getchar的话，我们要先getchar一次

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

int n, m;
int a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int ans;

int px[] = {1, -1, 0, 0, 1, 1, -1, -1};
int py[] = {0, 0, 1, -1, 1, -1, 1, -1};

// 打标记
void dfs(int x, int y)
{
    int xx, yy;
    vis[x][y] = 1;
    req(i, 0, 7)
    {
        xx = x + px[i], yy = y + py[i];

        if(xx > 0 && yy > 0 && xx <= n && yy <= m && a[xx][yy] && !vis[xx][yy]) dfs(xx, yy);
    }
}

void solve()
{
    char ch;
    cin >> n >> m;
    getchar();
    req(i, 1, n) // x
    {
        req(j, 1, m) // y
        {
            ch = getchar();
            if(ch == 'W') a[i][j] = 1;
            if(ch == '.') a[i][j] = 0;
        }
        getchar();
    }

    // req(i, 1, n)
    // {
    //     req(j, 1, m) putchar(a[i][j] + 48);
    //     putchar('\n');
    // }

    req(i, 1, n) req(j, 1, m)
    {
        if(a[i][j] && !vis[i][j])
        {
            dfs(i, j);
            ans++;
        }
    }

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