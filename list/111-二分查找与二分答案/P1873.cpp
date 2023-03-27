/**
 * @author OZLIINEX
 * @brief P1873 [COCI 2011/2012 #5] EKO / 砍树
 * @date 2023-03-27
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

#define MAXN 1000001
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
int a[MAXN];
int idx;
int ans;

void solve()
{
    cin >> n >> m;
    req(i,1,n) cin >> a[i];

    sort(a + 1,a + n + 1,greater<int>());

    for(idx = 2; idx <= n; idx++)
     {
        m -= (a[idx - 1] - a[idx]) * (idx - 1);
        if(m <= 0) break;
    }

    ans = a[idx] - m / (idx - 1);

    // 这个 - m / (idx - 1) 实际上是加法，我们可以注意到上面那个for循环的最后一次迭代
    // m是有可能小于0的，例如下面这个情况： 20 19 18 10，我们希望拿到10m的木棍，按照上述算法
    // 我们最后一次裁剪将会直接剪到10，实际上我们不需要裁这么多
    // 这个就是给他加回去，让多出来的m平摊到每一颗已经裁剪过的树上，如果平摊不了的话，意味着
    // 就只能多裁这么多，这也利用了整数除法抹小数点的性质


    cout << ans;

    // 20 19 18 17 16 15

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