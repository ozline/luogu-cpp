/**
 * @author OZLIINEX
 * @brief P3143 [USACO16OPEN] Diamond Collector S
 * @date 2023-04-01
 */


// 做的蛮久的，一开始用了单调队列，被这个题单坑了！
// 其实就是双指针题，不过其实也有难度

// 首先，我们既然知道双指针，那么大概率和perfix和suffix有关
// 我们可以利用一个遍历遍历出每个点i，左边可以取的最大数量，右边可以取的最大数量
// 然后我们合并计算就可以了

// 好，这个如何合并计算？
// 思考了很久，就又卡在这了

// 实际上，我们可以利用一点点DP思想，我们的perfix和suffix可以更改定义为
// perfix[i]: 点i左边的数组中，最大的连续子数组的长度
// suffix[i]: 点i右边的数组中，最大的连续子数组的长度
// 然后我们再用一个for加起来不就好了

// 思维提升了很多感觉

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

struct Node
{
    ll val, idx;

    Node(ll a, ll b):val(a),idx(b){};
    Node():val(0),idx(0){};
    bool operator < (const Node &a) const
    {
        return val < a.val;
    }
};

ll n, k;
ll a[MAXN];

ll l, r;
ll idxl, idxr; // 记录l的终点位置和i的起点位置


// 第i个点左边可以取的最大数量，第i个点右边可以取的最大数量
ll perfix[MAXN], suffix[MAXN];

ll ans;

void solve()
{
    n = read(), k = read();
    req(i, 1, n) a[i] = read();
    sort(a + 1, a + 1 + n);

    l = 1, r = n;
    req(i, 1, n)
    {
        while(a[i] - a[l] > k) l++;
        while(a[r] - a[n + 1 - i] > k) r--;

        perfix[i] = max(perfix[i - 1], i - l + 1);
        suffix[n + 1 - i] = max(suffix[n - i + 2], r - (n + 1 - i) + 1);
    }

    req(i, 1, n) ans = max(ans, perfix[i] + suffix[i + 1]);

    // debugvar(idxl);
    // debugvar(idxr);
    printf("%lld\n", ans);
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