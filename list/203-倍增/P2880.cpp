/**
 * @author OZLIINEX
 * @brief P2880 [USACO07JAN] Balanced Lineup G
 * @date 2023-04-02
 */

// 这道题可以用线段树做，但是这是倍增题单里的
// 考虑到不会ST表，我抄了个题解来学习ST表

// ST表：sparse-table，是一个用于解决可重复贡献的问题的数据结构
// 例如，你想要一个多次查询某个区间内的最大值/最小值，就可以用ST表
// 关于ST表，可以看这个wiki：https://oi-wiki.org/ds/sparse-table/

// 倍增的代码意义我觉得可以表述为 maxn[i][k]，其中k表示2^k

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

int maxn[180010][22], minn[180010][22];
int n, m;


// 替代 std::log 函数
int logn[180010];
void init_log()
{
    logn[1] = 0;
    req(i, 2, 180000) logn[i] = logn[i >> 1] + 1;
}

// 查询[l, r]内最大值和最小值的差
// 其中查询最大值和查询最小值的可以直接背下来
int st(int l, int r)
{
    int s = logn[r - l + 1], x, y;
    x = max(maxn[l][s], maxn[r - (1 << s) + 1][s]); // 区间最大
    y = min(minn[l][s], minn[r - (1 << s) + 1][s]); // 区间最小

    return x - y;
}

void solve()
{
    init_log();
    n = read(), m = read();

    req(i, 1, n) maxn[i][0] = minn[i][0] = read();

    // 这里的21表示的是2^21，我们要保证这个上界比数据范围大
    req(i, 1, 21) req(j, 1, n - (1 << i) + 1)
    {
        // 可以直接背
        maxn[j][i] = max(maxn[j][i - 1], maxn[j + (1 << (i - 1))][i - 1]);
        minn[j][i] = min(minn[j][i - 1], minn[j + (1 << (i - 1))][i - 1]);
    }

    // 开始查询
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