/**
 * @author OZLIINEX
 * @brief P3397 地毯
 * @date 2022-12-05
 */

/**
 * 做前缀和题单的时候刷到的这道题
 * 做对这道题不是很难，因为数据给的实在是太小了
 * 但是如何应用前缀和呢？
 * 我们只需要在地毯的左边一列和右边一列打上记好即可
 * 例如这张图
 * 0 0 0 0 0 0
 * 0 +1 0 0 0 -1
 * 0 +1 0 0 0 -1
 * 0 +1 0 0 0 -1
 * 0 +1 0 0 0 -1
 * 0 0 0 0 0 0
 * 实际上就是对应了地毯（2，2）（5，5）的定义
 * 输出的时候只需要按行输出，行内进行前缀和就知道了
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

#define MAXN 2001
#define INF 0x3f3f3f3f
#define INFLL 1LL<<60
#define writespace(a) write(a),putchar(' ')
#define writeln(a) write(a),putchar('\n')
#define req(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define fastio() std::ios::sync_with_stdio(false), std::cin.tie(0)
#define NAME(a) (#a)

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

int n, m;
int board[MAXN][MAXN];


void solve()
{
    int x1, x2, y1, y2;

    n = read(), m = read();

    while(m--)
    {
        x1 = read(), y1 = read(), x2 = read(), y2 = read();
        req(i,x1,x2) board[i][y1] ++, board[i][y2 + 1] --;
    }

    req(i, 1, n)
    {
        req(j, 1, n) printf("%d ",board[i][j] += board[i][j - 1]);
        putchar('\n');
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