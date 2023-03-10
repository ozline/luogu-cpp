/**
 * @author OZLIINEX
 * @brief P5638 【CSGRound2】光骓者的荣耀
 * @date 2022-12-05
 */

/*
    ..太简单了
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

#define MAXN 2000001
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

ll n, k;
ll a[MAXN], prefix[MAXN];
ll discount;

void solve()
{
    scanf("%lld %lld",&n, &k);
    req(i, 1, n)
    {
        scanf("%lld", &a[i]);
        prefix[i] = prefix[i - 1] + a[i];
        // if(i == 1) prefix[1] = a[i], discount = prefix[1];
        if(i >= k) discount = max(discount, prefix[i] - prefix[i - k]);
        // 此处要更改为i >= k 而不是 i > k, 否则会漏掉从1开始的跳跃
        else discount = max(discount, prefix[i] - prefix[1]);
    }

    printf("%lld", prefix[n] - discount);

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