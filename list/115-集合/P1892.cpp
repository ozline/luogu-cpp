/**
 * @author OZLIINEX
 * @brief P1892 [BOI2003]团伙
 * @date 2023-04-04
 */

// 似乎不能用路径压缩，看了一下 n < 1000, m < 5000; 数据量蛮小的
// 那么可以考虑在merge和find中做文章

// 我们可以开一个set数组，每个set对应着编号为i的敌人的列表
// 然后我们可以在合并的时候进行检查，检查二者关系是否为敌人，是的话则不合并

// 那么问题又出现了，假设现在有一个已经合并的集合 例如 1->2，我们已知2和3没有敌对关系，但是1和3有敌对关系
// 我们如何检查出3不能加入这个集合？可以考虑合并2和1的时候把set转移过去。因为数据量最多的也就10^3量级

// 结果上面这个分析p用没有，又把代码打复杂了
// 实际上我连题目都没读对，E和F乱了，E是好朋友，F是敌人？是个鬼啊！
// 总而言之上课刷题并不是一个很好的选择，还是回家刷吧

// 只需要存一个数组，记录每个人的敌人，然后在合并的时候检查一下即可
// 提高题难度好像也没有很难呢，只是需要注意一下


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

#define MAXN 10001
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
    int fa[MAXN];

    void init(int x)
    {
        req(i, 0, x + 100) fa[i] = i;
    }

    int find(int x)
    {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    void merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if(fx != fy) fa[fx] = fy;
    }
};

struct Node
{
    int p, q, opt; // 0 = E, 1 = F

    bool operator<(const Node &obj) const {
        return opt > obj.opt;
    }
};

int n, m, cnt;
Node a[MAXN];
DisjoinSet s;

int enemy[MAXN];
bool vis[MAXN];

void solve()
{
    char ch;
    int p, q;
    cin >> n >> m;
    s.init(n);
    req(i, 1, m)
    {
        cin >> ch >> p >> q;
        // a[i].opt = (ch == 'E') ? 0 : 1;

        if(ch == 'F') s.merge(p, q);
        else
        {
            if(enemy[p]) s.merge(enemy[p], q);
            else enemy[p] = s.find(q);

            if(enemy[q]) s.merge(enemy[q], p);
            else enemy[q] = s.find(p);
        }
    }

    req(i, 1, n) vis[s.find(i)] = true;
    req(i, 1, n) if(vis[i]) cnt++;

    printf("%d\n", cnt);
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    fastio();
    solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}