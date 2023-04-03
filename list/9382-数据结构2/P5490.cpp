/**
 * @author OZLIINEX
 * @brief P5490 【模板】扫描线
 * @date 2023-04-02
 */


// 扫描线模板题，当然也可以参考P1884，放在201文件夹里了

// 扫描线的一般解题思路： 离散化 + 线段树

// 刚刚静下心来思考了一下，这个扫描线中的线段树的使用和普通版本的区间是不一样的
// 它实际上是用整颗线段树表示现在某一个数的大小，在这道题中，表示的是某根线上边长

// 可以直接观察solve()函数中最后一个for遍历
// 本质上是遍历离散化后的line数组，这个line数组是什么呢
// 可以观察到这就是一根根扫描线的抽象数据结构，不过只包含了每个正方形的入口(y = x1)和出口(y = x2)这两根
// 我们在每次枚举中，对线段树进行add操作，实际上这道题来说可以翻译为更新——更新这棵树代表的值的大小
// 更新完，意味着我们当前的线段树表示的就是这根扫描线对应的长度，乘以到下一根扫描线之间的距离
// 就是两根扫描线之间的面积
// 累加求和即可

// 其实应该是我不理解离散化的原因，扫描线学起来很痛苦
// 离散化本质就是一个映射，用连续的短数组映射到长数组
// 例如，我们可以定义 1-100 2-1000 3-10000 4-10^4
// 如果我们用常规套路，我们至少要定义10^4大小的数组，而离散化后只需要定义4大小的即可

// 那么，怎么离散化呢？看代码吧。

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
    ll l, r, sum, len;
    // 左端点，右端点，区间和，加法懒标记
};

int val[MAXN];
Node t[MAXN << 2];
struct Segmentree
{
    #define p2  (p << 1)
    #define p21 (p << 1 | 1)

    void build(int p, int l, int r)
    {
        t[p].l = l, t[p].r = r;
        if(l == r){ return; }

        int mid = (t[p].l + t[p].r) >> 1;

        build(p2, l, mid);
        build(p21, mid + 1, r);
    }

    void add(int p, int l, int r, int v)
    {
        if(r < t[p].l || l > t[p].r) return;
        if(l <= t[p].l && t[p].r <= r) t[p].sum += v;
        else add(p2, l, r, v), add(p21, l, r, v);

        if(t[p].sum) t[p].len = val[t[p].r + 1] - val[t[p].l];
        else t[p].len = t[p2].len + t[p21].len;
    }
};

struct Line
{
    int x, yh, yl, t;
    // 横坐标，高度起点，高度终点，扫描线类型

    bool operator<(const Line &obj) const {
        if(x == obj.x) return t > obj.t;
        return x < obj.x;
    }
};

int n;              // 题意
Line line[MAXN];    // 扫描线
Segmentree seg;     // 线段树
int rk[MAXN], cnt;  // 离散化

ll ans;

void solve()
{
    int x1, y1, x2, y2;
    scanf("%d", &n);
    req(i, 1, n)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        line[(i << 1) - 1].x = x1, line[i << 1].x = x2; // 扫描线横坐标
        line[(i << 1) - 1].yh = line[i << 1].yh = y2;   // 起点高度
        line[(i << 1) - 1].yl = line[i << 1].yl = y1;   // 终点高度
        line[(i << 1) - 1].t = 1, line[i << 1].t = -1;  // 扫描线类型

        rk[++cnt] = y1, rk[++cnt] = y2; // 离散化准备
    }

    n <<= 1; // n *= 2;

    // 离散化
    sort(rk + 1, rk + 1 + n);
    cnt = unique(rk + 1, rk + 1 + n) - rk - 1;

    int maxn;
    req(i, 1, n)
    {
        int pos1 = lower_bound(rk + 1, rk + 1 + cnt, line[i].yh) - rk;
        int pos2 = lower_bound(rk + 1, rk + 1 + cnt, line[i].yl) - rk;
        val[pos1] = line[i].yh, val[pos2] = line[i].yl;
        line[i].yh = pos1, line[i].yl = pos2;
    }

    sort(line + 1, line + 1 + n);
    seg.build(1, 1, n);

    req(i, 1, n - 1)
    {
        seg.add(1, line[i].yl, line[i].yh - 1, line[i].t);
        ans += t[1].len * (line[i + 1].x - line[i].x);

        // 根节点的长度 * 下一段距离 = 这一块矩形面积
    }

    printf("%lld\n", ans);
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