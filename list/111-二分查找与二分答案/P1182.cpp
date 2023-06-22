/**
 * @author OZLIINEX
 * @brief P1182 数列分段 Section II
 * @date 2023-03-28
 */

// 一个溢出调了好久，真就不开ll见祖宗
// 最近刷的题好奇怪，老是把那种梗中遇到的情况都遇到了一遍

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


ll n, m;
ll a[MAXN];

bool check(ll limit)
{
    ll cnt = 1, last = 0;
    req(i, 1, n)
    {
        if(a[i] - a[last] > limit)
        {
            cnt++;
            last = i - 1; // 因为超过限制，只能裁切上一个
            // debug("spilt i = %d cnt = %d\n", i, cnt);
        }
    }
    // debug("limit = %d cnt = %d m = %d\n",limit, cnt, m);

    return cnt <= m;
}

void solve()
{
    // 思路：二分答案，也就是说，我们限定最大一块的大小，然后看看能不能分出m块或者比m块还少
    // 如果比m块来的少，那么就说明这个答案太大了，我们需要缩小答案
    // 如果刚好等于m块，说明这是我们需要的答案
    // 如果大于m块，说明我们需要扩大答案
    // 二分的l我们设定为数组中的最小数字，r代表数组中的所有数字和
    ll l = 0, r, mid, tmp;

    n = read(), m = read();
    req(i, 1, n)
    {
        tmp = read();
        a[i] = a[i - 1] + tmp;
        l = max(l, tmp);
    }

    r = a[n] + 1;

    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }

    printf("%lld\n", l);

}