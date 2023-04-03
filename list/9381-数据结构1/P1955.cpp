/**
 * @author OZLIINEX
 * @brief P1955 [NOI2015] 程序自动分析
 * @date 2023-04-03
 */


// 这道题炸出来了一个逆天结果 R106901617 1个A + 1个RE + 4个WA + 4个TLE
// 这道题我第一版代码写出来感觉没啥好写的了，就提交了一下，然后果不其然出现了这个逆天结果..

// 后面去看了一下数据范围，好家伙，1e9，单纯的开一整个数组是肯定不行了，内存直接爆
// 肯定要先离散化
// 做到这道题的时候已经遇到了很多个离散化的题了，基本上操作就是开一个新数组，然后这个数组存放要离散化的数据
// 然后sort数组，再lower_bound一下，把结果更新到原来的数据，就比如 ops[i].i = lower_bound(...)
// 如果需要提取原数据，就在struct上再开几个元素存放离散化后的idx，然后使用的时候拿idx去数据数组里找
// 反正这时候数据数组已经是排序过了的

// 然后就是简单的操作，我们是需要先把要并的都给并完，然后开始查询


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

#define MAXN 2000001
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

struct DisjoinSet
{
    int f[MAXN];

    void init(int x)
    {
        req(i, 0, x) f[i] = i;
    }

    int find(int x)
    {
        if(f[x] == x) return x;
        return f[x] = find(f[x]);
    }

    void merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if(fx != fy) f[fx] = fy;
    }
};

struct Node
{
    int i, j, e;
    Node(int a, int b, int c): i(a), j(b), e(c) {};
    Node(): i(0), j(0), e(0) {};

    bool operator<(const Node &obj) const {
        return e > obj.e;
    }
};

int T, n;
DisjoinSet s;
Node ops[MAXN];
bool flag;

int tmp[MAXN], cnt;

void solve()
{
    T = read();
    while(T--)
    {
        n = read(), flag = false, cnt = 0;
        req(i, 1, n)
        {
            scanf("%d%d%d", &ops[i].i, &ops[i].j, &ops[i].e);
            tmp[++cnt] = ops[i].i, tmp[++cnt] = ops[i].j;
        }

        // 离散化
        sort(tmp + 1, tmp + 1 + cnt);
        cnt = unique(tmp + 1, tmp + 1 + cnt) - tmp - 1;
        req(i, 1, n)
        {
            ops[i].i = lower_bound(tmp + 1, tmp + 1 + cnt, ops[i].i) - tmp;
            ops[i].j = lower_bound(tmp + 1, tmp + 1 + cnt, ops[i].j) - tmp;
        }


        s.init(cnt);
        sort(ops + 1, ops + 1 + n);

        req(i, 1, n)
        {
            Node now = ops[i];
            debugvar(ops[i].e);
            if(now.e == 1) s.merge(now.i, now.j);
            if(now.e == 0) if(s.find(now.i) == s.find(now.j)){ flag = true; break; }
        }

        puts(flag ? "NO" : "YES");
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