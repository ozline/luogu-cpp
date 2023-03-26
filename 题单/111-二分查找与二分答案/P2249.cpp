/**
 * @author OZLIINEX
 * @brief P2249 【深基13.例1】查找
 * @date 2023-03-26
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

int find(int x)
{
    int l = 1, r = n;
    while(l < r && l >= 1 && r <= n)
    {
        int mid = (l + r) >> 1;
        if(a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if(a[l] != x) return -1;
    else
    {
        // 不需要下面这句话，遇到相同的数字，会在上述二分中不断逼近最左侧的
        // while((l - 1) >= 0 && a[l - 1] == x) l--;
        return l;
    }
}

void solve()
{
    n = read(), m = read();
    req(i, 1, n) a[i] = read();
    req(i, 1, m) writespace(find(read()));
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