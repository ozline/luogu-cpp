/**
 * @author OZLIINEX
 * @brief P1884 [USACO12FEB]Overplanting S
 * @date 2023-04-02
 */

// 这道题是扫描线学习题，不是自己做的，在做了P1496的离散化后决定巩固一下
// Ref: https://ofnoname.blog.luogu.org/solution-p1884

// 参考题解：https://www.luogu.com.cn/blog/happy404/solution-p5490
// 扫描线模板：P5490

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

int qy[MAXN], m;

struct Segtree
{
    #define i0 (i << 1)
    #define i1 (i << 1 | 1)
    int l[MAXN << 2], r[MAXN << 2], sum[MAXN << 2], len[MAXN << 2];

    void init(int i, int ll, int rr)
    {
        l[i] = ll, r[i] = rr, sum[i] = len[i] = 0;
        if (ll == rr) return;
        int mid = (ll + rr) >> 1;
        init(i0, ll, mid);
        init(i1, mid + 1, rr);
    }

    void add(int i, int ll, int rr, int c)
    {
        if(rr < l[i] || r[i] < ll) return;
        if (ll <= l[i] && r[i] <= rr) sum[i] += c;
        else add(i0, ll, rr, c), add(i1, ll, rr, c);

        if(sum[i]) len[i] = qy[r[i] + 1] - qy[l[i]];
        else len[i] = len[i0] + len[i1];
    }
};

// 扫描线
struct Node
{
    // x: 横坐标，y1: 纵坐标下界，y2: 纵坐标上界, c: 1=左端点，-1=右端点
    int x, y1, y2, c;
    Node(int a, int b, int c, int d): x(a), y1(b), y2(c), c(d) {};
    Node(): x(0), y1(0), y2(0), c(0) {};

    bool operator<(const Node &obj) const {
        return x < obj.x;
    }
};

int n;
Segtree seg;
Node a[MAXN];
unordered_map<int, int> mp;

ll ans;

void solve()
{
    int x0, y0, x1, y1;
    scanf("%d", &n); mp.clear();
    req(i, 1, n)
    {
        scanf("%d%d%d%d", &x0, &y1, &x1, &y0);
        a[i] = Node(x0, y0, y1, 1);
        a[i + n] = Node(x1, y0, y1, -1);
        qy[++m] = y0, qy[++m] = y1;
    }

    // 离散化
    sort(qy + 1, qy + m + 1);
    m = unique(qy + 1, qy + m + 1) - qy - 1;

    req(i, 1, m) mp[qy[i]] = i;

    // 线段树
    seg.init(1, 1, n <<= 1);
    sort(a + 1, a + n + 1);
    req(i, 1, n)
    {
        seg.add(1, mp[a[i].y1], mp[a[i].y2] - 1, a[i].c);
        ans += (ll)seg.len[1] * (a[i + 1].x - a[i].x);
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