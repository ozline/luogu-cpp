/**
 * @author OZLIINEX
 * @brief P1638 逛画展
 * @date 2023-04-01
 */

// 在一个很神奇的地方卡住了，其实没有很难
// 二分l和r后，根据我的逻辑应该再check一下l，以更新ans
// 然后我一直没更新，就卡着了

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

#define MAXN 1000001
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

int n, m;
int a[MAXN];
queue<int> q;
int cnt[MAXN], vis; //记录访问次数

// 确定范围
int l, r, mid;

int ans;

bool check(int x)
{
    vis = 0, ans = 1;
    memset(cnt, 0, sizeof(cnt));
    while(!q.empty()) q.pop();

    for(; ans <= n; ans++)
    {
        q.push(a[ans]);
        if(cnt[ a[ans] ] == 0) vis++;
        cnt[ a[ans] ]++;

        while(!q.empty() && q.size() > x)
        {
            cnt[q.front()]--;
            if(cnt[q.front()] == 0) vis--;
            q.pop();
        }

        debug("vis = %d, m = %d\n\n", vis, m);

        if(vis == m) break;
    }
    return vis == m;
};

void solve()
{
    n = read(), m = read();
    req(i, 1, n) a[i] = read();
    l = 0, r = n;
    while(l < r)
    {
        mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    check(l);
    printf("%d %d\n", ans - l + 1, ans);
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