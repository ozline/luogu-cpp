/**
 * @author OZLIINEX
 * @brief P3853 [TJOI2007]路标设置
 * @date 2023-03-28
 */

// 因为先做了1182，所以这到题起手就是80分
// 然后卡在了2# 10# 和Subtask 1#
// 先说附加测试点，这个测试点是测试check函数中的参数x的，如果这个x==0，那么我们是不能直接除的
// 很明显，如果x==0，cnt=∞，我们直接返回false
// 接下来是2#和10# 这两个测试点也是测试check函数中的除法的
// 考虑两个路灯分别在60、90，此时x=10，我们主观角度上会发现应该插入2个路灯
// 但是我们的算法是(a[i] - a[i - 1]) / x，答案是3，我们应该改成(a[i] - a[i - 1] - 1)


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

#define DEBUG

#define MAXN 200001
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

ll l, n, k;
ll a[MAXN];

bool check(ll x)
{
    if(x == 0) return false;
    ll cnt = 0;
    req(i, 1, n)
    {
        if(a[i] - a[i - 1] > x) cnt += (a[i] - a[i - 1] - 1) / x;
    }
    if(l - a[n] > x) cnt += (l - a[n] - 1) / x;
    return cnt <= k;
}

void solve()
{
    ll le = 1, r = l, ans = 0, mid, tmp;
    l = read(), n = read(), k = read();
    req(i, 1, n) a[i] = read();
    while(le <= r)
    {
        mid = (le + r) >> 1;
        if(check(mid)) r = mid - 1;
        else le = mid + 1;
    }

    printf("%lld\n", le);
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