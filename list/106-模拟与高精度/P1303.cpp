/**
 * @author OZLIINEX
 * @brief P1303 A*B Problem
 * @date 2022-12-15
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

#define DEBUG

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

/**
 * @brief 字符串翻转
 */
void string_reverse(char *a)
{
    int len = strlen(a);
    req(i, 0, (len - 1) >> 1)
        swap(a[i], a[len - 1 - i]);
}

/**
 * @brief 高精度乘法
 *
 * @param a 被乘数
 * @param b 乘数
 * @param c 结果
 * @return int 结果长度
 */
int cal_mul(char *a, char *b, int *c)
{
    int lena = strlen(a), lenb = strlen(b);
    int len = lena + lenb - 1, cf = 0;

    string_reverse(a), string_reverse(b);
    memset(c, 0, sizeof(char) * len);

    req(i, 0, lena - 1)
    {
        req(j, 0, lenb - 1)
            c[i + j] += (a[i] - '0') * (b[j] - '0');
    }

    // 处理进位
    req(idx, 0, len - 1)
    {
        if(cf) c[idx] += cf;
        cf = c[idx] / 10, c[idx] %= 10;
    }
    while(cf)
    {
        c[len] += cf;
        cf = c[len] / 10, c[len] %= 10;
        len++;
    }

    // 解决前导零，但保留零
    while(!c[len - 1] && len-- > 1);

    // c数组翻转
    req(i, 0, (len - 1) >> 1) swap(c[i], c[len - 1 - i]);

    return len;
}

char a[MAXN], b[MAXN];
int c[MAXN * 2 + 1], len;

void solve()
{
    cin >> a;
    cin >> b;
    len = cal_mul(a, b, c);
    req(i, 0, len - 1) putchar(c[i] + 48);
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