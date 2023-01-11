/**
 * @author OZLIINEX
 * @brief P2234 [HNOI2002]营业额统计
 * @date 2023-01-09
 */

/**
 * 学习一下, set自带的lower_bound的时间复杂度大约为O(logN)
 * 而STL库中的lower_boun函数对set使用的话，时间复杂度为O(N)
 *
 * 查了一下:
 * 对于可随机访问的有序容器使用 algorithm 库中的 lower_bound 和 upper_bound 函数时间复杂度为O(logN)
 * 但对于set，multiset这种不能随机访问的有序容器，要用其自带的 lower_bound 和 upper_bound 的时间复杂度才为 O(logN)。
 *
 * lower_bound: 返回一个iterator，这个迭代器表示的是第一个不小于val的元素
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

#define MAXN 32768
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

int n;
int current;
ll ans;
set<int> s;
set<int>::iterator it, temp;

void solve()
{
    n = read();
    s.insert(INF);
    s.insert(-INF);
    req(i, 1, n)
    {
        current = read();
        if(i > 1)
        {
            it = s.lower_bound(current);
            if(*it != current)
            {
                temp = it, temp--;
                ans+= min(abs(*it - current), abs(*temp - current));
            }
        }
        else ans += current;
        s.insert(current);
    }
    printf("%lld\n",ans);
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