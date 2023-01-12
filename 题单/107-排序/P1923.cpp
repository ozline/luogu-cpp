/**
 * @author OZLIINEX
 * @brief P1923 第k小的数
 * @date 2022-12-15
 */

/**
 * 我们以{4, 3, 2, 1, 5}为例(下标从1开始)
 * 我们经过第一轮快排后，可以发现数字变为了
 * {1, 3, 2, 4, 5} i = 2, j = 3
 * {}
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

#define MAXN 5000005
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

int n, k;
int a[MAXN];

void quick_sort(int left, int right)
{
    int i = left, j = right, mid = a[(left + right) / 2];

    while(i <= j)
    {
        while(a[i] < mid) i++;
        while(a[j] > mid) j--;
        if(i <= j)
        {
            // a[i] ^= a[j], a[j] ^= a[i], a[i] ^= a[j];
            swap(a[i], a[j]);
            i++, j--;
        }
    }

    if(k <= j) quick_sort(left, j);
    else if(k >= i) quick_sort(i, right);
    else
    {
        printf("%d", a[j + 2]);
    }
}

void solve()
{
    n = read(), k = read();
    req(i, 1, n) a[i] = read();
    quick_sort(1, n);
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