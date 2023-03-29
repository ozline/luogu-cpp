/**
 * @author OZLIINEX
 * @brief P1803 凌乱的yyy / 线段覆盖
 * @date 2023-03-29
 */

// 贪心，这个贪心感觉有必要写一下的
// 我一开始思考的是按持续时间排序，然后贪心开始时间最早的
// 写完过了例子后一交，好，爆零
// 后面想了一下，应该以结束时间来排序，我们尽可能的覆盖更多的区间

// 是的，我忘记这道题的标题了，覆盖区间
// 我们面对一排的区间，应当如何选择使得我们选择的区间不重复且数量最大？
// 当然是按结束时间来排啊，排完后我们模拟一个指针，从左到右扫描
// 每次扫描到一个区间，我们判断一下这个区间的开始时间是否大于指针的位置
// 大于的话就说明我们可以走这个区间，小于的话我们就跳过这个区间

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

#define MAXN 1001001
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
    int l, r, dur; // 开始，结束，持续时间

    bool operator<(const Node &b) const
    {
        // if (dur == b.dur) return l < b.l;
        // return dur < b.dur;

        return r < b.r;
    }
};



int n;
Node a[MAXN];
int ans;

void solve()
{
    n = read();
    req(i, 1, n) a[i].l = read(), a[i].r = read(), a[i].dur = a[i].r - a[i].l;

    sort(a + 1, a + n + 1);

    int cur = 0;

    req(i, 1, n)
    {
        if (a[i].l >= cur)
        {
            cur = a[i].r;
            ans++;
        }
    }

    writeln(ans);
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