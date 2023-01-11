
/**
 * @author OZLIINEX
 * @brief P1160 队列安排
 * @date 2023-01-04
 */

// STL List模板题！


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
#include <list>

#define DEBUG

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

int n, m;
list<int> l;
list<int>::iterator pos[MAXN], it;
int vis[MAXN];

void solve()
{
    n = read();

    l.push_front(1);
    pos[1] = l.begin();
    req(i, 2, n)
    {
        int k = read(), p = read();
        if(p == 0) pos[i] = l.insert(pos[k], i);
        else pos[i] = l.insert(next(pos[k]), i);
    }
    m = read();
    req(i, 1, m)
    {
        int x = read();
        if(vis[x]) continue;
        l.erase(pos[x]);
        vis[x] = true;
    }
    for(it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    return;
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}