/**
 * @author OZLIINEX
 * @brief P2032 扫描
 * @date 2023-03-31
 */

// 题目大意：有一个窗口，从左到右滑动，问每次右移1个单位，窗口内最大值

// 考虑维护一个优先队列（也叫做大根堆？），这个优先队列里存放每个点
// 我们就当这个队列是那个窗口，但是这个队列里也可能存在不在窗口内的点，我们不需要管
// 因为我们只需要求一个最大值即可
// 我们每次就取这个队列的top，如果它的idx比窗口允许的范围还小，我们弹出
// 一直弹到top是一个合法的Node，那么这个Node就是我们需要的点

// 时间复杂度是NlogN，当然也可以用线段树做
// 有类似的题：P1440、P1886，我发现我都做过了，不过是用线段树做的
// 这次就用正常解法做啦

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

struct Node
{
    int val, idx;

    Node(int a, int b):val(a),idx(b){};
    Node():val(0),idx(0){};

    bool operator<(const Node &obj) const {
        return val < obj.val;
    }
};

int n, k;
int a[MAXN], ans;
priority_queue<Node> q;

void solve()
{
    n = read(), k = read();
    req(i, 1, n)
    {
        q.push(Node(read(), i));
        if(i < k) continue;
        while(!q.empty() && q.top().idx + k <= i) q.pop();
        printf("%d\n", q.top().val);
    }
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