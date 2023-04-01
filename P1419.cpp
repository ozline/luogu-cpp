/**
 * @author OZLIINEX
 * @brief P1419 寻找段落
 * @date 2023-04-01
 */

// 在床上看这道题的时候发现好像思路蛮清晰的

// 就是单调队列 + 二分答案，没了！
// 核心还是，用单调队列忽略序号的问题
// 我们直接使用while(!q.empty() && q.top().idx + ... < ...) q.pop()就行了

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

    Node(int a, int b):val(a),idx(b){};
    Node():val(0),idx(0){};

    bool operator<(const Node &obj) const {
        return val > obj.val;
    }
};

int n, s, t;
ll a[MAXN], perfix[MAXN];
priority_queue<Node> q;
double l = - 10000.0, r = 10000.0, mid;

bool check(double x)
{
    while(!q.empty()) q.pop();

    req(i, s, n)
    {
        // if(i <= r && ((double)perfix[i] - i * x) >= 0)
        // {
        //     debug("1");
        //     return true;
        // }
        if(i <= t && (double)perfix[i] - i * x >= 0) return true;

        while(!q.empty() && (q.top().idx + t - 1 < i || q.top().idx + s - 1 > i)) q.pop();
        if(!q.empty() && ((double)perfix[i] - i * x) >= ((double)q.top().val - (q.top().idx - 1) * x))
        {
            debug("x: %lf, %lld~%d, q.top(): %lld, perfix: %lld\n", x, q.top().idx, i, q.top().val, perfix[i]);
            return true;
        }

        q.push(Node(perfix[i], i));
    }
    return false;
}

void solve()
{
    n = read(), s = read(), t = read();
    req(i, 1, n)
    {
        scanf("%lld", &a[i]);
        perfix[i] = perfix[i - 1] + a[i];
    }

    while(r - l >= 1e-4)
    {
        mid = (l + r) / 2.0;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.3lf\n", l);
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