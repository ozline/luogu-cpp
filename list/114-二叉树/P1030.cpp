/**
 * @author OZLIINEX
 * @brief P1030 [NOIP2001 普及组] 求先序排列
 * @date 2023-01-14
 */

/**
 * 前序遍历：根左右
 * 中序遍历：左根右
 * 后序遍历：左右根
 *
 * 这道题与P1827异曲同工之妙
 * 但是这道题是中序遍历和后序遍历，P1827是前序遍历和中序遍历
 * 主要关注前序遍历结果和后序遍历结果，一个根在头一个根在尾
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

#define MAXN 500001
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

void get_beford(string in, string after)
{
    if(in.size())
    {
        char ch = after[after.size() - 1];
        int k = in.find(ch);
        printf("%c", ch); // 输出根
        get_beford(in.substr(0, k), after.substr(0, k)); // 左子树
        get_beford(in.substr(k + 1), after.substr(k, in.size() - k - 1)); // 右子树
    }
}

string inord, aftord;

void solve()
{
    cin >> inord >> aftord;
    get_beford(inord, aftord);
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