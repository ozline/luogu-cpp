/**
 * @author OZLIINEX
 * @brief P4387 【深基15.习9】验证栈序列
 * @date 2023-01-09
 */

/**
 * 其实就是模拟一个栈和一个队列
 *
 * pushed数组存放在数组a，poped数组则直接读入queue
 * 然后进行模拟，不断的往stack中push数组a的数
 * push完每个数后，我们进行判断，栈顶数字是否和queue.front()的一致
 * 如果一致的话则两边同时pop()，然后进行下一个匹配，一直到stack空或两个数字不匹配
 *
 * 最后判断一下queue是否为空就可以进行输出Yes或No了
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

int q, n;
int a[MAXN], b[MAXN];

void solve()
{
    q = read();
    while(q--)
    {
        n = read();
        stack<int> s;
        queue<int> q;
        req(i, 1, n) a[i] = read();
        req(i, 1, n) q.push(read());
        req(i, 1, n)
        {
            s.push(a[i]);
            while(!s.empty() && s.top() == q.front())
            {
                s.pop();
                q.pop();
            }
        }

        puts(q.empty() ? "Yes" : "No");
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