/**
 * @author OZLIINEX
 * @brief P4447 [AHOI2018初中组]分组
 * @date 2023-03-28
 */

// 这道题最后是copy了热门题解
// 这道题做了好久..但其实不难
// 一直在纠结如何规避奇怪的分组，但是忽略了标题就是分组

// 思路其实很简单，我们可以假设(模拟?)出多个组
// 然后我们遍历数组，把新的数字插入合适的分组里即可，如果没有的话则新建一个
// 这里我们需要注意，我们对于每个分组，我们只需要它的最大值和组长
// 也就是说，我们没必要为每个分组开个stack，我们只需要用一个size[]和q[]即可
// 其中，size[]表示的是第i个数组的长度，q[]表示的是要加入这个分组，我们需要多大的能力
// 然后就是简单遍历
// 注意，由于我们期望的是尽可能的让组变长，因此遇到相同的组的时候，我们优先向短的那个组添加
// 观察代码可以发现，遇到实力相同的组，id靠前的组的长度永远不小于id靠后的组的长度

// 嗯。。题目就做完了，其实没有很难

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

#define MAXN 200001
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

int n;
int a[MAXN];
int ans = INF;
int siz[MAXN], cnt, q[MAXN];

void solve()
{
    n = read();
    req(i, 1, n) a[i] = read();
    sort(a + 1, a + 1 + n);


    req(i, 1, n)
    {
        int pos = lower_bound(q + 1, q + 1 + cnt, a[i]) - q;
        while(q[pos + 1] == a[i] && pos < cnt) pos++;

        if(pos > cnt || q[pos] != a[i]) siz[++cnt] = 1, q[cnt] = a[i] + 1;
        else siz[pos]++, q[pos]++;
    }

    req(i, 1, cnt) ans = min(ans, siz[i]);

    writeln(ans);
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