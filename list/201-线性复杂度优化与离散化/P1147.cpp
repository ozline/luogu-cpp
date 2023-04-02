/**
 * @author OZLIINEX
 * @brief P1147 连续自然数和
 * @date 2023-04-01
 */

// 秒杀的一道题，前缀和遍历即可

// 但是看题解，这道题可以数学优化：https://www.luogu.com.cn/blog/gzw2005/solution-p1147


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

#define MAXN 2000011
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

int m;
ll a[MAXN];

int l = 1;

void solve()
{
    m = read();

    req(i, 1, m) a[i] = a[i - 1] + i;

    req(i, 1, m) {
        if(a[i] - a[l] < (ll)m) continue;
        while(a[i] - a[l] > (ll)m) l++;
        if(a[i] - a[l] == (ll)m && l + 1 != i) printf("%d %d\n", l + 1, i);
    }
}

void solve_math()
{
    m = read();
    for(int k1 = sqrt(2 * m); k1 > 1; k1--)
    {
        if(2 * m % k1 == 0 && (k1 + 2 * m / k1) % 2)
        {
            int k2 = 2 * m / k1;
            printf("%d %d\n", (k2 - k1 + 1) / 2, (k1 + k2 - 1) / 2);
        }
    }
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    // fastio();
    // solve();
    solve_math();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}