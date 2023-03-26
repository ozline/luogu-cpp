/**
 * @author OZLIINEX
 * @brief P1551 亲戚
 * @date 2023-01-22
 */

// 并查集模板
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

#define MAXN 5001
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

int fa[MAXN];

void set_init()
{
    req(i, 0, MAXN - 1) fa[i] = i;
}

int set_find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = set_find(fa[x]);
}

void set_union(int x, int y)
{
    int fx = set_find(x);
    int fy = set_find(y);

    if(fx != fy) fa[fy] = fx;
}

int n, m, p;

void solve()
{
    set_init();

    n = read(), m = read(), p = read();

    req(i, 1, m)
    {
        int x = read(), y = read();
        set_union(x, y);
    }

    while(p--)
    {
        int a = read(), b = read();
        puts((set_find(a) != set_find(b)) ? "No" : "Yes");
    }


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