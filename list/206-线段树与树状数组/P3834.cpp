/**
 * @author OZLIINEX
 * @brief P3834 【模板】可持久化线段树 2
 * @date 2023-04-05
 */


// 这个与P3919的区别在于，这个是正统的可持久化线段树，而P3919是一种简化的可持久化线段树
// 但是实际上核心逻辑是一致的

// 难点在于查询思路，如何查询区间第k大的数 比如询问一个[l, r]中的第k大
// 我们先求[1, r]中有多少个数字，然后再求[1, l-1]中有多少个数字
// 每一个节点的权值相减，得到的就是[l, r]中的数字的个数
// 所以对于k，如果 k <= tree[p].val 就往左边查找，反之往右边查找

// 对于这道题，我们实际上做的就是，首先初始化整棵树
// 然后对于每次insert新的数字，我们就拷贝一份树，然后在新的树上添加数字
// 查询的时候，我们就查询两棵树p和q，对应的就是【r和l】，然后求出两棵树的差值，就是答案

// 对于这道题，就是离散化 + 可持久化线段树

// 先对数据离散，然后我们依据离散后的结果（lower_bound）来建树，实际上就是根据数字所对应的rank来建树，也就是权值线段树

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

int n, m;
int a[MAXN], b[MAXN];

struct Node
{
    int l, r, val;
    int il, ir; // 左儿子和右儿子的位置
};

struct PersistentSeg
{
    Node tree[MAXN << 5];
    int cnt;

    int clone(int p)
    {
        tree[++cnt] = tree[p];
        return cnt;
    }

    int init(int l ,int r)
    {
        int p = ++cnt;
        tree[p].l = l, tree[p].r = r; // 设定这个点维护的左右区间

        if(l == r) return p;

        int mid = (l + r) >> 1;
        tree[p].il = init(l, mid);
        tree[p].ir = init(mid + 1, r);
        return p;
    }

    int insert(int p, int pos)
    {
        p = clone(p), tree[p].val++; // 克隆节点
        if(tree[p].l == tree[p].r) return p;

        int mid = (tree[p].l + tree[p].r) >> 1;
        if(pos <= mid) tree[p].il = insert(tree[p].il, pos);
        if(mid < pos) tree[p].ir = insert(tree[p].ir, pos);
        return p;
    }

    int query(int p, int q, int k)
    {
        if(tree[p].l == tree[p].r) return tree[p].l;

        int x = tree[tree[p].il].val - tree[tree[q].il].val;

        if(k <= x) return query(tree[p].il, tree[q].il, k);
        return query(tree[p].ir, tree[q].ir, k - x);
    }
};

PersistentSeg seg;
int root[MAXN];

void solve()
{
    n = read(), m = read();
    req(i, 1, n) b[i] = a[i] = read();
    sort(b + 1, b + 1 + n);
    int len = unique(b + 1, b + 1 + n) - b - 1;

    root[0] = seg.init(1, len);

    req(i, 1, n)
    {
        int it = lower_bound(b + 1, b + 1 + len, a[i]) - b;
        root[i] = seg.insert(root[i - 1], it);
    }

    while(m--)
    {
        int l = read(), r = read(), k = read();
        printf("%d\n", b[seg.query(root[r], root[l - 1], k)]);
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