/**
 * @author OZLIINEX
 * @brief P2251 质量检测 线段树（？）
 * @date 2022-07-27
 */

#include "header.hpp"
#define MAXN 500001


class SegmentTree
{
public:
    struct Node
    {
        int left;
        int right;
        ll min;
    };

    SegmentTree():maxn(MAXN)
    {
        this->init();
    }

    SegmentTree(int maxn):maxn(maxn)
    {
        this->init();
    }

    void init()
    {
        tree = new Node[maxn<<2];
        a = new int[maxn+2];

        for(int i=1;i<=maxn;i++) a[i] = 0;
    }

    void push_up(int node)
    {
        // tree[node].sum = tree[node<<1].sum + tree[node<<1|1].sum;
        tree[node].min = min(tree[node<<1].min , tree[node<<1|1].min); //最小值
    }

    void build(int node, int l, int r)
    {
        tree[node].left = l;
        tree[node].right = r;

        if( l == r)
        {
            tree[node].min = a[l];
            return;
        }

        int mid = ( l + r ) >> 1;
        this->build(node<<1, l, mid);
        this->build(node<<1|1, mid+1, r);

        push_up(node);
    }

    ll query_min(int node, int l, int r)
    {
        if( l <= tree[node].left && r >= tree[node].right) return tree[node].min;

        int mid = ( tree[node].left + tree[node].right ) >> 1;

        ll ans = INFLL;

        if( l <= mid) ans = min(ans, this->query_min(node<<1, l, r));
        if( r > mid) ans = min(ans, this->query_min(node<<1|1, l, r));

        return ans;
    }


    int *a;

private:
    Node *tree;
    int maxn;

protected:
};

void solve()
{

    int n = read(), m = read();

    SegmentTree tree(MAXN);

    for(int i=1;i<=n;i++) read(tree.a[i]);

    tree.build(1,1,n);

    for(int i=1;i<=n-m+1;i++)
    {
        writeln( tree.query_min(1,i,i+m-1) );
    }
}