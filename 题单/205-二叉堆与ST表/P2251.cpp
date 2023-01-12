/**
 * @author OZLIINEX
 * @brief P2251 质量检测 线段树（？）
 * @date 2022-07-27
 */
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

// #define DEBUG
#define MAXN 500001
#define INF 0x3f3f3f3f
#define INFLL ( 1LL<<60 )
#define debug(...) fprintf(stdout,__VA_ARGS__)

typedef long long ll;
using namespace std;


template<typename T>
T read(T &x) {
    x = 0;
    T w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    x *= w;
    return x;
}

template<typename T>
inline void write(T x) {
    if( x < 0)
    {
        putchar('-');
        x = -x;
    }
    static int sta[35];
    int top = 0;
    do sta[top++] = x % 10, x /= 10;
    while (x);
    while (top) putchar(sta[--top] + 48);
}

template<typename T>
inline void writeln(T x)
{
    write(x);
    putchar('\n');
}

template<typename T>
inline void writespace(T x)
{
    write(x);
    putchar(' ');
}
/* END OF TEMPLATE */


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

int main()
{
    #ifdef DEBUG
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    clock_t start,finish;
    double totaltime;
    start = clock();
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    /*START*/

    int n,m;
    read(n),read(m);

    SegmentTree tree(MAXN);

    for(int i=1;i<=n;i++) read(tree.a[i]);

    tree.build(1,1,n);

    for(int i=1;i<=n-m+1;i++)
    {
        writeln( tree.query_min(1,i,i+m-1) );
    }


    /*END*/

    #ifdef DEBUG
    finish = clock();
    totaltime = (double)(finish-start)/CLOCKS_PER_SEC*1000;
    printf("\n耗时: %.6lf ms\n",totaltime);
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}