/**
 * @author OZLIINEX
 * @brief P1093 奖学金
 * @date 2022-12-15
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

#define MAXN 301
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

struct Mark
{
    int a, b, c;
    int idx;
    Mark(int a, int b, int c):a(a),b(b),c(c){};
    Mark():a(0),b(0),c(0){};

    bool operator<(const Mark &obj) const
    {
        if((a + b + c) != (obj.a + obj.b + obj.c))
        {
            return (a + b + c) > (obj.a + obj.b + obj.c);
        }
        else if(a != obj.a) return a > obj.a;
        // else if(b != obj.b) return b > obj.b;
        // else if(c != obj.c) return c > obj.c;
        else return idx < obj.idx;

    }
};

int n;
Mark a[MAXN];

void solve()
{
    n = read();
    req(i, 1, n)
    {
        a[i].a = read(), a[i].b = read(), a[i].c = read(), a[i].idx = i;
    }
    sort(a + 1, a + 1 + n);
    req(i, 1, 5)
    {
        printf("%d %d\n",a[i].idx, a[i].a + a[i].b + a[i].c);
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