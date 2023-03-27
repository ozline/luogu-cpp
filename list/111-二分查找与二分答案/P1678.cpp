/**
 * @author OZLIINEX
 * @brief P1678 烦恼的高考志愿
 * @date 2023-03-27
 */


// d了半天，发现是局部变量和全局变量重名了，我****

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

#define MAXN 100001
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

int m, n;
int a[MAXN], b[MAXN];

ll ans;

void solve()
{
    ll l, r, mid, tmp;
    m = read(), n = read();
    req(i, 1, m) a[i] = read(); // 学校
    req(i, 1, n) b[i] = read(); // 学生

    sort(a + 1, a + m + 1);
    sort(b + 1, b + n + 1);

    l = 1;

    // 我们忽略了只有一个的情况..
    if(m == 1)
    {
        req(i, 1, n) ans += abs(a[1] - b[i]);
        printf("%lld\n", ans);
        return;
    }

    req(i, 1, n)
    {
        r = m + 1;

        // 二分找第一个不大于 b[i] 的数的下标
        while(l < r)
        {
            mid = (l + r) >> 1;
            if (a[mid] <= b[i]) l = mid + 1;
            else r = mid;
        }
        if(abs(a[l] - b[i]) < abs(a[l - 1] - b[i])) tmp = abs(a[l] - b[i]);
        else
        {
            tmp = abs(a[l - 1] - b[i]);
            l--;
        }

        // 修复上述漏洞：a[0]我们是没有定义的
        if(l == 0) ans += a[1] - b[i], l = 1;
        else ans += tmp;
    }

    printf("%lld\n", ans);

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