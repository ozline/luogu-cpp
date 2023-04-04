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

#define MAXN 1000009
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