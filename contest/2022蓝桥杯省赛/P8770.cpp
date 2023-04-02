/**
 * @author OZLIINEX
 * @brief P8770 [蓝桥杯 2022 省 A] 填空问题
 * @date 2023-04-02
 */

// 这道题包含两道题，具体请参考：https://www.luogu.com.cn/problem/P8770

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

void solve()
{
    /*
        试题A：裁纸刀
        依据题意，我们首先就要裁4次
        其次，不能拼起来剪
        我们先裁出20行，也就是 (20 - 1) 次裁剪
        其次，对于每一行，我们都要裁剪 (22 - 1) 次
        所以一共是 4 + (20 - 1) + (22 - 1) * 20 = 4 + 19 + 420 = 443

        试题B：博弈论

    */
    string ans [] = {
        "443", // 双引号中替换为 A 题的答案
        "LLLV", // 双引号中替换为 B 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
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