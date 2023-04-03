/**
 * @author OZLIINEX
 * @brief P1419 寻找段落
 * @date 2023-04-01
 */

// 在床上看这道题的时候发现好像思路蛮清晰的

// 就是单调队列 + 二分答案，没了！
// 核心还是，用单调队列忽略序号的问题
// 我们直接使用while(!q.empty() && q.top().idx + ... < ...) q.pop()就行了

// 230403： 调不动了，已经忘记了原代码的逻辑了，索性学习了一下优秀题解（其实是抄作业！

// 基本是发现了为啥上次失败了，因为特么perfix是ll而不是double
// 这道题就先这样闭关了，再写就不礼貌了

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

int n, s, t;
ll a[MAXN];
double l = -10000.0, r = 10000.0, mid, perfix[MAXN];

bool check(double x)
{
    req(i, 1, n) perfix[i] = perfix[i - 1] + double(a[i]) - x;

    int head = 1, tail = 0, q[MAXN];

    req(i, s, n)
    {
        while(head <= tail && perfix[q[tail]] > perfix[i - s]) tail--;
        q[++tail] = i - s;
        while(head <= tail && q[head] < i - t) head++;

        if(head <= tail && perfix[i] - perfix[q[head]] >= 0) return true;
    }

    return false;
}

void solve()
{
    scanf("%d%d%d", &n, &s, &t);
    req(i, 1, n)
    {
        scanf("%lld", &a[i]);
        perfix[i] = perfix[i - 1] + a[i];
    }

    while(r - l > 1e-5)
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