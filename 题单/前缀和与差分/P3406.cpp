/**
 * @author OZLIINEX
 * @brief P3406
 * @date 2022-12-05
 */

/**
 * 来源于前缀和题单里的题，第一次的时候有点懵
 * 分析了一下发现只需要统计每一段的访问次数，然后再和售价一起计算一下就是最终结果
 * 因为每一段的售价只有2种情况
 *
 * 1.原价 * 访问次数
 * 2.折扣价 * 访问次数 + 卡价
 *
 * 接下来就是如何处理访问次数了
 * 第一次想到的是直接统计每一段的访问次数，提交后70分，T了2个点 WA了一个点
 * 考虑到可能是快读问题，去掉快读后各个点情况依旧
 * 分析一下可能导致超时的原因，发现是统计访问次数时使用while把经历的每一段都++
 * 如果出现大量的1->10^5和10^5->1，时间复杂度直接加起来了
 * 考虑一下昨天做题时的差分思想，把每一段旅程的头站++，尾站--
 * 然后处理前缀和就可以了
 * 然后就从T2 WA1 变到了 WA3..
 * 浪费了一次下载次数下载下来，一看out，明显超过int32了，把ans改成ll后提交还是如此
 * 然后尝试把cnt和vis数组都改成ll，就过了..
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
#include <unordered_map>

// #define DEBUG

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
using namespace std;


inline int read() {
    int x = 0, w = 1; char ch = 0;
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return (x*w);
}

inline void write(int x) {
    if(x<0) putchar('-'), x = -x;
    static int sta[35]; int top = 0;
    while(x) {sta[top++] = x % 10, x /= 10;}
    while (top) putchar(sta[--top] + 48);
}
/* END OF TEMPLATE */

int i,j;
int n, m;
int p[MAXN];
ll cnt[MAXN]; // 记录第i段铁路访问情况
ll vis[MAXN];

ll ans;

void solve()
{
    int from, to;
    int a, b, c;
    scanf("%d %d",&n,&m);
    req(i, 1, m)
    {
        scanf("%d",&p[i]);
        if(i == 1) continue;
        from = min(p[i], p[i - 1]), to = max(p[i], p[i - 1]);
        cnt[from]++, cnt[to]--;
    }

    req(i,1,n) vis[i] = vis[i - 1] + cnt[i];

    req(i, 1, n - 1)
    {
        scanf("%d %d %d",&a, &b, &c);
        ans += min(vis[i] * a, vis[i] * b + c);
    }

    printf("%lld",ans);
    return;
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    fastio(); solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}