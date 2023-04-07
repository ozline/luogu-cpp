/**
 * @author OZLIINEX
 * @brief P4017 最大食物链计数
 * @date 2023-04-07
 */


// 本来是Vector存边，被我改成了链式前向星

// 结果链式前向星的边要开好大，最后5002 << 7过了，似乎是5002 * 128 = 640256
// 然后看了一下M的范围，果然

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

#define MAXN 5002
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

const int mod = 80112002;

int n, m, ans;
int in[MAXN], out[MAXN], sum[MAXN];

vector<int> nex[MAXN];
queue<int> q;


struct Node { int to, next; };

int head[MAXN], cnt;
Node edge[MAXN << 7];           // 这个Node要开好大
void add_edge(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void solve()
{
    req(i, 1, MAXN - 1) head[i] = -1;
    n = read(), m = read();
    req(i, 1, m)
    {
        int x = read(), y = read();
        in[y]++, out[x]++;
        add_edge(x, y);
    }

    req(i, 1, n) if(!in[i]) sum[i] = 1, q.push(i);

    while(!q.empty())
    {
        int now = q.front(); q.pop();

        for(int i = head[now]; i != -1; i = edge[i].next)
        {
            int next = edge[i].to;
            in[next]--; sum[next] = (sum[next] + sum[now]) % mod;
            if(in[next] == 0) q.push(next);
        }
    }

    req(i, 1, n) if(!out[i]) ans = (ans + sum[i]) % mod;

    printf("%d\n", ans);
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