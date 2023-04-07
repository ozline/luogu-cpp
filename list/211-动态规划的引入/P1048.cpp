/**
 * @author OZLIINEX
 * @brief [NOIP2005 普及组] 采药
 * @date 2023-04-07
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

struct Node
{
    int consume; //消耗的时间
    int value; //草药价值
};

int t, m;
Node node[MAXN];
int dp[MAXN];       //表示有多少钱时的最优解


int f[MAXN][MAXN]; // f[i][j] 表示采第i株药，花费时间j可以采集到的草药的最大价值

/*
    不采摘第i株     f[i][j] = f[i - 1][j]
    采摘第i株       f[i][j] = max(f[i][j], f[i - 1][j - t[i]] + pri[i])

    我们还有dp[i]，表示花费的时间j时，可以采摘到的草药的最大价值
*/


void solve()
{
    t = read(), m = read();

    for(int i=1;i<=m;i++)
    {
        node[i].consume = read();
        node[i].value = read();
    }

    // i表示第i种草药
    for(int i=1;i<=m;i++)
    {
        // j表示花费时间j来采摘草药
        for(int j=t;j>=node[i].consume;j--)
        {
            // 花费时间j可以采摘到的最大价值 = max(不采摘当前草药的最大价值 + 当前草药价值, 当前花费解)
            dp[j] = max(dp[j - node[i].consume] + node[i].value,dp[j]);
        }
    }

    writeln(dp[t]);
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