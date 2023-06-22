/**
 * @author OZLIINEX
 * @brief P2846 [USACO08NOV]Light Switching G
 * @date 2023-04-05
 */

// 与 P3870 [TJOI2009] 开关 完全一致，包括读入输出
// 甚至样例都一样


#include "header.hpp"
#define MAXN 500001
struct Node
{
    int l, r;
    int cnt, tag;
};


int n, m;
int a[MAXN];

struct Segmentree
{
    #define p2  (p << 1)
    #define p21 (p << 1 | 1)
    Node tree[MAXN << 2];

    void init(int p, int l, int r)
    {
        tree[p].l = l, tree[p].r = r;
        if(l == r)
        {
            tree[p].cnt = (a[l]) ? 1 : 0;
            return;
        }

        int mid = (l + r) >> 1;
        init(p2, l, mid);
        init(p21, mid + 1, r);
        tree[p].cnt = tree[p2].cnt + tree[p21].cnt;
    }

    void push_down(int p)
    {
        if(tree[p].tag)
        {
            tree[p2].cnt = (tree[p2].r - tree[p2].l + 1) - tree[p2].cnt;
            tree[p21].cnt = (tree[p21].r - tree[p21].l + 1) - tree[p21].cnt;

            tree[p2].tag ^= 1;
            tree[p21].tag ^= 1;
        }
        tree[p].tag = 0;
    }

    void update(int p, int l, int r)
    {
        if(l <= tree[p].l && tree[p].r <= r)
        {
            tree[p].cnt = (tree[p].r - tree[p].l + 1) - tree[p].cnt;
            tree[p].tag ^= 1;
            return;
        }

        push_down(p);

        int mid = (tree[p].l + tree[p].r) >> 1;
        if(l <= mid) update(p2, l, r);
        if(mid < r) update(p21, l, r);

        tree[p].cnt = tree[p2].cnt + tree[p21].cnt;
    }

    ll query(int p, int l, int r)
    {
        if(l <= tree[p].l && tree[p].r <= r) return tree[p].cnt;

        push_down(p); ll ans = 0;

        int mid = (tree[p].l + tree[p].r) >> 1;
        if(l <= mid) ans += query(p2, l, r);
        if(mid < r) ans += query(p21, l, r);
        return ans;
    }
};

Segmentree seg;

void solve()
{
    n = read(), m = read();
    seg.init(1, 1, n);

    int op, x, y;
    while(m--)
    {
        op = read(), x = read(), y = read();
        if(op == 0) seg.update(1, x, y);
        else printf("%lld\n",seg.query(1, x, y));
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