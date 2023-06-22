/**
 * @author OZLIINEX
 * @brief P3373 【模板】线段树 2
 * @date 2023-04-03
 */

// 第一次碰线段树是在去年的时候，我其实还有留着去年的代码
// 但是很明显，去年的代码已经不适用今年啦
// 所以我重新写了一份易读版的线段树

// 依据题意，这个线段树需要支持：区间查询、乘法、加法，同时要取模
// 那么ll必不可少了

// 在Segmentree中我构建了如下函数：build()、push_down()、add()、mul()、query()
// 其实都比较好理解，主要就是这个push_down()难度挺大
// 这个是因为这个线段树采用了lazytag，每一次查询、加、乘都需要先更新对应数字
// 懒标记的使用可以让线段树趋于O(NlogN)

// 其实理解了线段树后，整个数据结构最难的应该就是push_down()函数
// 我选择了先乘后加，而在add()函数中我则是直接给add加上数字，在mul()中同样也需要对add乘以相应数字

// 只有加法的在P3372，实际上很多题目基本上都是用线段树做一个引子，然后再做一些其他的事情
// 在这种题目中，线段树的push_down()函数就可以不用写了，因为不需要lazytag
// 而且基本上只需要一个build()和query()就可以了


#include "header.hpp"
#define MAXN 200001

struct Node
{
    int l, r;
    ll sum, add, mul;
};

int a[MAXN];            // 普通数组
Node tree[MAXN << 2];   // 线段树
int mod;                // 模数
struct Segmentree
{
    #define p2  (p << 1)
    #define p21 (p << 1 | 1)

    void build(int p, int l, int r)
    {
        tree[p].l = l, tree[p].r = r, tree[p].mul = 1;
        if(l == r){ tree[p].sum = a[l] % mod; return; }

        int mid = (l + r) >> 1;
        build(p2, l, mid);
        build(p21, mid + 1, r);
        tree[p].sum = (tree[p2].sum + tree[p21].sum) % mod;
    }

    void push_down(int p)
    {
        // 更新左右区间的sum
        tree[p2].sum =  tree[p2].sum * tree[p].mul;
        tree[p2].sum += tree[p].add * (tree[p2].r - tree[p2].l + 1);
        tree[p2].sum %= mod;

        tree[p21].sum = tree[p21].sum * tree[p].mul;
        tree[p21].sum += tree[p].add * (tree[p21].r - tree[p21].l + 1);
        tree[p21].sum %= mod;

        // 更新懒标记
        tree[p2].mul = tree[p2].mul * tree[p].mul % mod;
        tree[p21].mul = tree[p21].mul * tree[p].mul % mod;

        tree[p2].add = (tree[p2].add * tree[p].mul + tree[p].add) % mod;
        tree[p21].add = (tree[p21].add * tree[p].mul + tree[p].add) % mod;

        tree[p].mul = 1, tree[p].add = 0;
    }

    void add(int p, int l, int r, int val)
    {
        if(l <= tree[p].l && tree[p].r <= r)
        {
            tree[p].sum += val * (tree[p].r - tree[p].l + 1) % mod;
            tree[p].add = (tree[p].add + val) % mod;
            return;
        }

        push_down(p);

        int mid = (tree[p].l + tree[p].r) >> 1;
        if(l <= mid) add(p2, l, r, val);
        if(mid < r) add(p21, l, r, val);

        tree[p].sum = (tree[p2].sum + tree[p21].sum) % mod;
    }

    void mul(int p, int l, int r, int val)
    {
        if(l <= tree[p].l && tree[p].r <= r)
        {
            tree[p].sum = (tree[p].sum * val) % mod;
            tree[p].mul = (tree[p].mul * val) % mod;
            tree[p].add = (tree[p].add * val) % mod;
            return;
        }

        push_down(p);

        int mid = (tree[p].l + tree[p].r) >> 1;
        if(l <= mid) mul(p2, l, r, val);
        if(mid < r) mul(p21, l, r, val);

        tree[p].sum = (tree[p2].sum + tree[p21].sum) % mod;
    }

    ll query(int p, int l, int r)
    {
        if(l <= tree[p].l && tree[p].r <= r) return tree[p].sum;

        push_down(p); ll ans = 0;

        int mid = (tree[p].l + tree[p].r) >> 1;
        if(l <= mid) ans += query(p2, l, r);
        if(mid < r) ans += query(p21, l, r);

        return ans % mod;
    }
};

Segmentree seg;
int n, m;

int op, x, y, k;

void solve()
{
    scanf("%d%d%d", &n, &m, &mod);
    req(i, 1, n) scanf("%d", &a[i]);

    seg.build(1, 1, n);

    while(m--)
    {
        scanf("%d%d%d", &op, &x, &y);

        if(op < 3) scanf("%d", &k);

        if(op == 1) seg.mul(1, x, y, k);
        if(op == 2) seg.add(1, x, y, k);
        if(op == 3) printf("%lld\n", seg.query(1, x, y));
    }
}