/**
 * @author OZLIINEX
 * @brief P601 A+B Problem（高精）
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

// #define DEBUG

#define MAXN 1001
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


// 字符串翻转
void string_reverse(char *a)
{
    int len = strlen(a);
    req(i, 0, (len - 1) >> 1)
        swap(a[i], a[len - 1 - i]);
}

// 字符串交换
void string_swap(char *a, char *b)
{
    int len = max(strlen(a), strlen(b));
    req(i, 0, len - 1) swap(a[i], b[i]);
}

// 高精度加法(非负)
void cal_add(char *a, char *b, char *c)
{
    int lena = strlen(a), lenb = strlen(b);
    int len = max(lena, lenb), cf = 0;

    string_reverse(a), string_reverse(b);
    memset(c, 0, sizeof(char) * len);

    req(idx, 0, len - 1)
    {
        if(cf) c[idx] ++;
        if(idx < lena) c[idx] += (a[idx] - 48);
        if(idx < lenb) c[idx] += (b[idx] - 48);
        cf = c[idx] / 10;
        c[idx] %= 10;
        c[idx] += 48;
    }

    if(cf) c[len] = 49; // 独特进位
    string_reverse(c);
}

char a[MAXN], b[MAXN], c[MAXN];

void solve()
{
    cin >> a;
    cin >> b;
    cal_add(a, b, c);
    printf("%s\n", c);
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
