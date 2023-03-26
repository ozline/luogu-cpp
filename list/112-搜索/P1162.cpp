/**
 * @author OZLIINEX
 * @brief P1162 填涂颜色
 * @date 2023-03-26
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

int n;
int a[MAXN][MAXN];

int px[] = {0, 0, 1, -1};
int py[] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    if(a[x][y] != 0) return;
    a[x][y] = 3;
    req(i, 0, 3)
    {
        int xx = x + px[i], yy = y + py[i];

        if(xx > 0 && xx <=n && yy > 0 && yy <=n && a[xx][yy] == 0) dfs(xx, yy);
    }
}

void solve()
{
    cin >> n;
    req(i, 1, n) req(j, 1, n) cin >> a[i][j];



    // 只要把边缘都搜一遍就行了嘛
    req(i, 1, n) dfs(1, i), dfs(n, i);
    req(i, 2, n - 1) dfs(i, 1), dfs(i, n);

    req(i, 1, n)
    {
        req(j, 1, n)
        {
            if(a[i][j] == 1) putchar(49);
            else if(a[i][j] == 3) putchar(48);
            else putchar(50);

            if(j != n) putchar(' ');
        }

        putchar('\n');
    }

    return;
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