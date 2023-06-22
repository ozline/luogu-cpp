/**
 * @author OZLIINEX
 * @brief P3954 [NOIP2017 普及组] 成绩
 * @date 2022-07-25
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
#define INFLL ( 1LL<<60 )
#define debug(...) fprintf(stdout,__VA_ARGS__)

typedef long long ll;
using namespace std;


template<typename T>
T read(T &x) {
    x = 0;
    T w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    x *= w;
    return x;
}

template<typename T>
inline void write(T x) {
    if( x < 0)
    {
        putchar('-');
        x = -x;
    }
    static int sta[35];
    int top = 0;
    do sta[top++] = x % 10, x /= 10;
    while (x);
    while (top) putchar(sta[--top] + 48);
}

template<typename T>
inline void writeln(T x)
{
    write(x);
    putchar('\n');
}

template<typename T>
inline void writespace(T x)
{
    write(x);
    putchar(' ');
}
/* END OF TEMPLATE */

void solve()
{
    int a,b,c;
    read(a),read(b),read(c);

    int ans = a*0.2 + b*0.3 + c*0.5;

    writeln(ans);
}