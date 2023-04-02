/**
 * @author OZLIINEX
 * @brief P8775 [蓝桥杯 2022 省 A] 青蛙过河
 * @date 2023-04-02
 */


// 前缀和 + 二分答案

// l = 1, r = n，然后正常二分
// check()怎么写呢？

// 对于给定的一个limit，这个lmit指的是小青蛙的跳跃范围
// 那么一定是有，在这个数组中的每个limit区间，都必须满足和 > 2x
// 也就是说对于每个区间来说，都必须让小青蛙可以跳2x下以上

// 考虑每个区间不重叠，也就是说把这个数组分成了若干区间
// 考虑小青蛙这时候跳到了某个区间的左端点，这时候它有两个选择
// 一个是跳到区间内，然后再跳出去，还有一个是直接跳到新的区间内
// 对于第一种情况，区间就需要承担它的跳跃1下，而另一个则不需要
// 这说明我们区间开大了，缩小区间，让他保证必须在这个区间跳1下
// 但是需要跳2下吗？不需要，因为我们可以让小青蛙跳到新的区间内

// 因此，我们只需要考虑每个区间的和能否不小于2x即可
// check函数写好了，那么就是二分答案了


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

int n, x;
int a[MAXN];

ll l, r, mid;
ll perfix[MAXN];

// limit指的是小青蛙最多能跳的距离
bool check(ll limit)
{
    req(i, limit, n - 1)
    {
        if(perfix[i] - perfix[i - limit] < x) return false;
    }
    return true;
}

void solve()
{
    scanf("%d%d", &n, &x); x <<= 1;
    req(i, 1, n - 1) scanf("%d", &a[i]), perfix[i] = perfix[i - 1] + a[i];

    l = 1, r = n - 1;

    while(l < r)
    {
        mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%lld\n", l);
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