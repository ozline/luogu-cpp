/**
 * @author OZLIINEX
 * @brief  P3811 【模板】乘法逆元
 * @date 2022-12-08
 */

/**
 * 1.欧拉定理
 * 如果a, p互质，那么a^(p-1) = 1 (mod p) 当p为质数时
 * 结合同余方程，可以知道 x == a^(p-2) (mod p) 求解即可
 *
 * 2.费马小定理
 * 如果p为质数，a与p互质，那么a^(p-1) = 1 (mod p)
 * 结合同余方程，可以知道 x == a^(p-2) (mod p) 求解即可
 *
 * 3.解不定方程
 * 解不定方程 ax == 1 (mod p) 等价于解不定方程 ax + py = 1
 * 可以用Exgcd求解
 * 由于p是质数，那么gcd(a, p) = 1;
 * 也就是求解不定方程 ax + by = gcd(a, b)
 *
 * 4.推导
 * https://www.luogu.com.cn/blog/user49618/solution-p3811
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

#define DEBUG

#define MAXN 4000001
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
    if(x == 0) { putchar('0'); return; }
    if(x<0) putchar('-'), x = -x;
    static int sta[35]; int top = 0;
    while(x) { sta[top++] = x % 10, x /= 10;}
    while (top) putchar(sta[--top] + 48);
}
/* END OF TEMPLATE */

int x, y;
void exgcd(ll a, ll b)
{
    if(!b){ x = 1, y = 0; return; }
    exgcd(b, a % b);
    int t = x;
    x = y, y = t - a / b * y;
}

ll quick_power(ll a, ll b, ll p)
{
    ll ans = 1, base = a % p;
    while(b)
    {
        if(b & 1) ans *= base, ans %= p;
        base *= base;
        base %= p;
        b >>= 1;
    }
    return ans;
}

int n, p;

ll inv[MAXN] = {0, 1};

void solve()
{
    n = read(), p = read();
    // req(i, 1, n) writeln(quick_power(i, p - 2, p)); //解法1和2
    // req(i, 1, n) //解法3
    // {
    //     exgcd(i, p);
    //     writeln((x % p + p) % p);
    // }

    puts("1");
    for(int i = 2; i <= n; i++)
    {
        inv[i] = (ll)p - (p / i) * inv[p % i] % p;
        printf("%lld\n", inv[i]);
    }
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