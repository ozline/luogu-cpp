/**
 * @author OZLIINEX
 * @brief P1719 最大加权矩形
 * @date 2022-12-05
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

#define MAXN 10001
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
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return (x*w);
}

inline void write(int x) {
    if(x<0) putchar('-'), x = -x;
    static int sta[35]; int top = 0;
    while(x) {sta[top++] = x % 10, x /= 10;}
    while (top) putchar(sta[--top] + 48);
}
/* END OF TEMPLATE */

int i, j, k, l;
int n, ans;
int a[MAXN][MAXN];
int dp[MAXN], temp[MAXN];


void solve()
{
    n = read();
    req(i, 1, n) req(j, 1, n) a[i][j] = read();

    req(i, 1, n)
    {
        memset(temp, 0, sizeof(temp));
        req(j, i, n)
        {
            req(k, 1, n) temp[k] += a[j][k];
            memset(dp, 0, sizeof(dp));
            req(l, 1, n)
            {
                dp[l] = max(dp[l], dp[l - 1] + temp[l]);
                ans = max(ans, dp[l]);
            }
        }
    }

    printf("%d", ans);

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