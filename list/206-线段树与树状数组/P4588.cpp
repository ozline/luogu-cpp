/**
 * @author OZLIINEX
 * @brief P4588 [TJOI2018]数学计算
 * @date 2023-04-05
 */


// 线段树的一个特殊应用，这个应用在扫描线部分涉及到了
// 实际上就是把线段树当成了一个数字的操作记录
// 这道题的操作就是一个乘法，一个除法（除以第num步的数字）

// 我们就对一个数字建立线段树，线段树的每个节点i代表第i个操作
// 在merge的时候sum更新为每个node相乘的结果，最后tr[1].sum就是答案了
// 除法的话就是把第i步置为1，这样相当于没进行操作

// 现在是基本理解扫描线了，但是还是不太会写，还是要多写几遍

#include "header.hpp"
#define MAXN 500001

struct Node
{
    ll l, r, sum;

    Node(int a, int b, int c):l(a),r(b),sum(c){};
    Node():l(0),r(0),sum(0){};
};

int M;
struct Segmentree
{
    #define p2  (p << 1)
    #define p21 (p << 1 | 1)

    Node tr[MAXN << 2];

    void init(int p, int l, int r)
    {
        tr[p] = Node(l, r, 1);
        if (l == r) return;
        int mid = (l + r) >> 1;
        init(p2, l, mid);
        init(p21, mid + 1, r);

        // tr[p].sum = (tr[p2].sum * tr[p21].sum) % M; // 反正都是1
    }

    void set(int p, int pos, int val)
    {
        if(tr[p].l == tr[p].r)
        {
            if(val < 1) val = 1;
            tr[p].sum = val % M;
            return;
        }

        int mid = (tr[p].r + tr[p].l) >> 1;
        if(pos <= mid) set(p2, pos, val);
        if(mid < pos) set(p21, pos, val);

        tr[p].sum = (tr[p2].sum * tr[p21].sum) % M;
    }
};

int q, T;
int op, num;
Segmentree tree;

void solve()
{
    T = read();
    while(T--)
    {
        q = read(), M = read();

        tree.init(1, 1, q);
        req(i, 1, q)
        {
            op = read(), num = read();
            if(op == 2) tree.set(1, num, 1);    // 把第pos操作置为1
            else tree.set(1, i, num % M);       // 把第pos操作置为num
            printf("%lld\n", tree.tr[1].sum % M);
        }
    }
}