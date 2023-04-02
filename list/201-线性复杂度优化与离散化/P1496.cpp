/**
 * @author OZLIINEX
 * @brief P1496 火烧赤壁
 * @date 2023-04-01
 */

// 这道题其实可以用线段树写
// 但是还是朴素一点吧，毕竟普及-

// 但是我是在离散化题单里写到这道题的
// 所以我从题解里抄了一个离散化的答案，学习一下离散化
// Ref: https://www.luogu.com.cn/blog/ZKR666/p1496-huo-shao-chi-bi-ti-xie

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
    ll a, b;
    Node(int a, int b): a(a), b(b) {};
    Node(): a(0), b(0) {};
    bool operator<(const Node &obj) const {
        return a < obj.a;
    }
};

int n;
Node a[MAXN];

ll len = -(1 << 31), ans;

// 贪心模拟
void solve()
{
    n = read();
    req(i, 1, n) a[i].a = read(), a[i].b = read();
    sort(a + 1, a + 1 + n);

    req(i, 1, n)
    {
        if(len > a[i].b - 1) continue;

        if(len <= a[i].a) ans += a[i].b - a[i].a;
        else ans += a[i].b - len;

        len = a[i].b;
    }

    printf("%lld\n", ans);
}


struct Item
{
    int l, nl; // 左 离散后
    int r, nr; // 右 离散后
};

Item item[MAXN];
int b[MAXN * 2];
int m[MAXN * 2], sum[MAXN * 2];


// 离散化 + 差分 + 前缀和
void solve_discretization()
{
    n = read();

    // 离散化，也就是求每个Item的nl和lr
    req(i, 1, n) item[i].l = read(), item[i].r = read(), b[i] = item[i].l, b[i + n] = item[i].r;

    sort(b + 1, b + 1 + n * 2);
    int k = unique(b + 1, b + 1 + n * 2) - b - 1;

    req(i, 1, n)
    {
        item[i].nl = lower_bound(b + 1, b + 1 + k, item[i].l) - b;
        item[i].nr = lower_bound(b + 1, b + 1 + k, item[i].r) - b;
    }

    // 差分 与 前缀和，其中m[i]表示的是差分数组, sum[i]表示的是前缀和
    req(i, 1, n) m[item[i].nl + 1]++, m[item[i].nr + 1]--;
    req(i, 1, k) sum[i] += sum[i - 1] + m[i];

    int l = 0, r = 0;
    req(i, 1, k)
    {
        if(sum[i] != 0 && sum[i - 1] == 0) l = i - 1;
        if(sum[i] != 0 && sum[i + 1] == 0) r = i, ans += b[r] - b[l];
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    // fastio();
    // solve();
    solve_discretization();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}