/**
 * @author OZLIINEX
 * @brief P1196 [NOI2002] 银河英雄传说
 * @date 2023-04-03
 */


// 银河英雄传说是一个我听了很多次的经典题了，与食物链相当

// 首先，题目已经暗示的很明显了，是并查集，但是问题就接踵而至了
// 题目要我们实现2个操作，一个是合并队列，这简单，还有一个是查询同一个队列中两个点之间的距离

// 我经过了一定的训练，到了做这道题的时候终于意识到了，我们不需要关心每一列中的队列具体长什么样
// 如果关心，我们是无法做到1s内输出全部答案的，可以注意到操作规模是10^5
// 我们使用cnt[i]来表示第i列有多少艘船，那么后续如果要合并队列的话，cnt相加即可
// 那么，现在解决了每一列中有多少艘船，我们现在需要解决，在每一列中如何统计两个船之间的距离
// 做过前缀和的题目可以注意到，求两个点之间的距离，可以采用perfix[i] - perfix[j]来求的
// 而每个perfix[i]表示的点i到原点的距离，我们可以类比这个操作，建立一个dis[i]数组
// 这个数组表示的是一个队列中，船i到队首的距离
// 我们可以维护这个dis数组，等答案需要的时候我们就利用(dis[i] - dis[j] + 1)即可

// 好的，现在来了，如何维护dis数组？很明显要维护dis数组，我们也要维护cnt数组
// 现在有一个初始化的并查集，我们执行了一次merge操作
// 好的，我们可以从merge下手
// 首先，我们求出fx和fx，也就是x和y的父亲
// 下一步，我们合并fx和fy，也就是f[fx] = fy，把fx往fy靠
// 同时，fx所在的列的船都要进入fy所在的列，也就是cnt[fy] += cnt[fx], cnt[fx] = 0
// 下一步，就要更新dis[fx]，注意到fx是跟在fy后面的，那么fy所在的列，fy排多少，fx就要排在它的下一个
// 所以我们有dis[fx] += cnt[fy];

// 接下来，我们需要考虑路径压缩，路径压缩的本质是，本来有a->b->c->d，那么很明显，我们查询c的时候可以把d/c更新到a
// 首先我们需要明确a, b, c, d几个点已经是同一列了，我们在merge()部分已经更新了cnt[fy] += cnt[fx]
// 因此我们只需要更新dis，回顾一下dis[i]的定义：第i个船到队首的距离
// 对于每一个船，我们都知道它的祖先（即使不是最近的），和它到祖先的距离，现在我们要做的就是更新它的dis
// 因为先前的dis只是针对它和它的祖先的，我们要更新到它的祖先的祖先...的祖先
// 自然要递归了，从d先递归到b（因为到a的时候直接return了），b更新一下自己的距离dis[b] += dis[a]
// 然后到c，c更新一下自己的距离dis[c] += dis[b]，因为c在b后面
// 同理更新d，最后代码写出来就是find()函数中的内容了


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


struct DisjoinSet
{
    int f[MAXN], dis[MAXN], cnt[MAXN];

    void init()
    {
        req(i, 0, MAXN - 1) f[i] = i, dis[i] = 0, cnt[i] = 1;
    }

    int find(int x)
    {
        if(f[x] == x) return x;
        int fx = find(f[x]);    // 先递归更新自己的父亲
        dis[x] += dis[f[x]];    // 然后再更新自己
        return f[x] = fx;
    }

    void merge(int x, int y)
    {
        int fx = find(x), fy = find(y);

        dis[fx] += cnt[fy];
        f[fx] = fy;
        cnt[fy] += cnt[fx];
        cnt[fx] = 0;
    }

    int caldis(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if(fx != fy) return -1;
        return abs(dis[x] - dis[y]) - 1;
    }
};

int T;
DisjoinSet s;

void solve()
{
    int x, y; char op;
    s.init();

    cin >> T;
    while(T--)
    {
        cin >> op >> x >> y;
        if(op == 'M') s.merge(x, y);
        if(op == 'C') printf("%d\n", s.caldis(x, y));
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