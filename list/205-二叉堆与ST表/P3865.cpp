/**
 * @author OZLIINEX
 * @brief P3865 【模板】ST 表
 * @date 2023-04-02
 */

// st表模板题
// 好好背吧！

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

#define MAXN 200001
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

const int p = 21;

int n, m;
int maxn[MAXN][p];
int logn[MAXN];


void init_log()
{
    logn[1] = 0;
    req(i, 2, MAXN) logn[i] = logn[i >> 1] + 1;
}

int st(int l, int r)
{
    int k = logn[r - l + 1];
    return max(maxn[l][k], maxn[r - (1 << k) + 1][k]);
}

void solve()
{
    init_log();
    n = read(), m = read();
    req(i, 1, n) maxn[i][0] = read();

    req(i, 1, p) req(j, 1, n - (1 << i) + 1)
    {
        maxn[j][i] = max(maxn[j][i - 1], maxn[j + (1 << (i - 1))][i - 1]);
    }

    req(i, 1, m)
    {
        int l = read(), r = read();
        writeln(st(l, r));
    }
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