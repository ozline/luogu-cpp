/**
 * @author OZLIINEX
 * @brief P2440 木材加工
 * @date 2023-03-27
 */


// 第一次拿了76，WA两个点，看了一下答案，好家伙
// 比如你有n段，其中n - 1个都很短，最后一个很长
// 那么你可以直接放弃那n - 1个，只从第n个跑..
// 把代码中的r = min(r, a[i]) 改成 r = max(r, a[i]) 就过了
// 草!
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

ll n, k;
int a[MAXN];

int l = 0, r = INF;

ll cal(int x)
{
    int res = 0;
    req(i, 1, n) res += a[i] / x;
    return res;
}

void solve()
{
    n = read(), k = read();
    req(i, 1, n) a[i] = read(), r = max(r, a[i]);

    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(cal(mid) >= k) l = mid;
        else r = mid - 1;
    }
    writeln(l);
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