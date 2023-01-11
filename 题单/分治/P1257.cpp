/**
 * @author OZLIINEX
 * @brief P1257 平面上的最接近点对
 * @date 2022-12-27
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

#define MAXN 10001
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

struct Node
{
    int x, y;
    double dist;
    Node():x(0),y(0){};
    Node(int a, int b):x(a),y(b){};

    double calDistance(const Node &obj) const
    {
        return sqrt((x - obj.x) * (x - obj.x) + (y - obj.y) * (y - obj.y));
    }

    void init()
    {
        x = read(), y = read();
        dist = (x * x + y * y);
    }

    bool operator<(const Node &obj) const
    {
        return dist < obj.dist;
    }
};

int n;
Node node[MAXN];
double ans = INF;



void solve()
{
    n = read();
    req(i, 1, n) node[i].init();

    sort(node + 1, node + n + 1);

    req(i, 1, n - 1)
    {
        req(j, i + 1, n)
        {
            if (node[j].dist - node[i].dist > ans) break;
            ans = min(ans, node[i].calDistance(node[j]));
        }
    }

    // req(i, 1, n)
    //     req(j, 1, n)
    //     {
    //         if(i == j) continue;
    //         ans = min(ans, node[i].calDistance(node[j]));
    //     }

    printf("%.4lf\n", ans);

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