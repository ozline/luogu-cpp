/**
 * @author OZLIINEX
 * @brief P4995 跳跳！
 * @date 2023-03-31
 */


// 写一波贪心思考
// 比如目前有 1 2 我们在地面， ->1->2还是->2->1呢
// 其实就是 1^2 + 2^2和3^2的比较
// 很明显，直接3^2更大
// 所以思路就是左右反复跳

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

ll n;
ll h[MAXN];

ll last = 0;
ll ans = 0;

void solve()
{
    n = read();
    req(i, 1, n) h[i] = read();
    sort(h + 1, h + 1 + n);
    req(i, 1, n)
    {
        if(i % 2)
        {
            ans += ll(pow(h[n + 1 - (i + 1) / 2] - last, 2));
            last = h[n + 1 - (i + 1) / 2];
        }
        else
        {
            ans += ll(pow(h[i / 2] - last, 2));
            last = h[i / 2];
        }
    }

    printf("%lld\n", ans);

    // 1: h[n] 2: h[1] 3: h[n - 1] 4: h[2]  5: h[n - 2]
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