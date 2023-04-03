/**
 * @author OZLIINEX
 * @brief P3372 【模板】线段树 1
 * @date 2023-04-03
 */


// 关于这颗线段树，请移步P3373

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
    ll l, r, sum, add, mul;
};

int a[MAXN];            // 普通数组
Node tree[MAXN << 2];   // 线段树
struct Segmentree
{
    #define p2  (p << 1)
    #define p21 (p << 1 | 1)

    void build(int p, int l, int r)
    {
        tree[p].l = l, tree[p].r = r, tree[p].mul = 1;
        if(l == r){ tree[p].sum = a[l]; return; }

        int mid = (l + r) >> 1;
        build(p2, l, mid);
        build(p21, mid + 1, r);
        tree[p].sum = (tree[p2].sum + tree[p21].sum);
    }

    void push_down(int p)
    {
        // 更新左右区间的sum
        tree[p2].sum =  tree[p2].sum * tree[p].mul;
        tree[p2].sum += tree[p].add * (tree[p2].r - tree[p2].l + 1);

        tree[p21].sum = tree[p21].sum * tree[p].mul;
        tree[p21].sum += tree[p].add * (tree[p21].r - tree[p21].l + 1);

        // 更新懒标记
        tree[p2].mul = tree[p2].mul * tree[p].mul;
        tree[p21].mul = tree[p21].mul * tree[p].mul;

        tree[p2].add = (tree[p2].add * tree[p].mul + tree[p].add);
        tree[p21].add = (tree[p21].add * tree[p].mul + tree[p].add);

        tree[p].mul = 1, tree[p].add = 0;
    }

    void add(int p, int l, int r, int val)
    {
        if(l <= tree[p].l && tree[p].r <= r)
        {
            tree[p].sum += val * (tree[p].r - tree[p].l + 1);
            tree[p].add = (tree[p].add + val) ;
            return;
        }

        push_down(p);

        int mid = (tree[p].l + tree[p].r) >> 1;
        if(l <= mid) add(p2, l, r, val);
        if(mid < r) add(p21, l, r, val);

        tree[p].sum = (tree[p2].sum + tree[p21].sum);
    }

    void mul(int p, int l, int r, int val)
    {
        if(l <= tree[p].l && tree[p].r <= r)
        {
            tree[p].sum = (tree[p].sum * val);
            tree[p].mul = (tree[p].mul * val);
            tree[p].add = (tree[p].add * val);
            return;
        }

        push_down(p);

        int mid = (tree[p].l + tree[p].r) >> 1;
        if(l <= mid) mul(p2, l, r, val);
        if(mid < r) mul(p21, l, r, val);

        tree[p].sum = (tree[p2].sum + tree[p21].sum);
    }

    ll query(int p, int l, int r)
    {
        if(l <= tree[p].l && tree[p].r <= r) return tree[p].sum;

        push_down(p); ll ans = 0;

        int mid = (tree[p].l + tree[p].r) >> 1;
        if(l <= mid) ans += query(p2, l, r);
        if(mid < r) ans += query(p21, l, r);

        return ans;
    }
};

int n, m;
Segmentree seg;

void solve()
{
    n = read(), m = read();
    req(i, 1, n) a[i] = read();

    seg.build(1, 1, n);

    req(i, 1, m)
    {
        int q = read(), x =
         read(), y = read();
        if(q == 1) seg.add(1, x, y, read());
        else printf("%lld\n", seg.query(1, x, y));
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