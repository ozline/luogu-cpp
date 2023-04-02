/**
 * @author OZLIINEX
 * @brief P4086 [USACO17DEC]My Cow Ate My Homework S
 * @date 2023-04-02
 */

// 没那么难，这道题看完题目思路基本就有了
// 就是处理几个前缀和，然后遍历（也是枚举）
// 不过是倒着处理，所以也可以叫后缀和？

// 需要注意的是，我们需要升序输出所有可能的k的值
// 也就是说，答案有时候不唯一
// 而且k不能为0！！

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

int n;
int a[MAXN];
int minx[MAXN]; // record the min value of a[i] in [i, n]
double avg[MAXN];  // record the average value of a[i] in [i, n]
int sum[MAXN];  // record the sum value of a[i] in [i, n]

double maxavg;
ll ans;

void solve()
{
    n = read();
    req(i, 1, n) a[i] = read();
    sum[n] = minx[n] = a[n];
    for(int i = n - 1; i > 0; i--)
    {
        minx[i] = min(minx[i+1], a[i]);
        sum[i] = sum[i + 1] + a[i];
    }

    for(int i = n - 1; i > 0; i--)
    {
        avg[i] = double(sum[i] - minx[i]) / (n - i);
        maxavg = max(maxavg, avg[i]);
    }

    req(i, 2, n)
    {
        // debug("avg[%d] = %lf, minx[%d] = %d, sum[%d] = %d\n", i, avg[i], i, minx[i], i, sum[i]);
        // 有个坑，有多个答案的时候，要每个都输出
        if(avg[i] == maxavg) printf("%d\n", i - 1);
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