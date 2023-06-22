/**
 * @author OZLIINEX
 * @brief P3919 【模板】可持久化线段树
 * @date 2023-04-04
 */

// 主席树模板题

// 主席树数组一般开到32倍，也就是左移5位
// 主席树与线段树的区别在于开点，可以认为主席树是一个动态开点的线段树
// 在每次的查找、更新过程中我们也需要开点，因此update和query函数的返回值都是一个int，表示当前节点的位置
// 其他部分就与线段树差异不大了

#include "header.hpp"
#define MAXN 1000009

struct Node
{
    int l, r, val;
    int il, ir; // 左儿子和右儿子的位置
};

int n, m, a[MAXN];

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

        if(l == r){ tree[p].val = a[l]; return p; }

        int mid = (l + r) >> 1;
        tree[p].il = init(l, mid); tree[p].ir = init(mid + 1, r);

        return p;
    }

    int update(int p, int pos, int val)
    {
        p = clone(p); // 克隆节点
        if(tree[p].l == tree[p].r){ tree[p].val = val; return p; }

        int mid = (tree[p].l + tree[p].r) >> 1;
        if(pos <= mid) tree[p].il = update(tree[p].il, pos, val);
        if(mid < pos) tree[p].ir = update(tree[p].ir, pos, val);

        return p;
    }

    int query(int p, int pos)
    {
        if(tree[p].l == tree[p].r) return tree[p].val;

        int mid = (tree[p].l + tree[p].r) >> 1;
        if(pos <= mid) return query(tree[p].il, pos);
        return query(tree[p].ir, pos);
    }
};


int root[MAXN]; // 每个版本的根节点
PersistentSeg seg;

void solve()
{
    // 版本， 操作， 位置， 值
    int p, pos, idx, val;
    n = read(), m = read();
    req(i, 1, n) a[i] = read();

    root[0] = seg.init(1, n);
    req(i, 1, m)
    {
        p = read(), pos = read(), idx = read();
        if(pos == 1)
        {
            val = read();
            root[i] = seg.update(root[p], idx, val);
        }
        else
        {
            printf("%d\n", seg.query(root[p], idx));
            root[i] = root[p]; // 查询后也要更新版本
        }
    }
}