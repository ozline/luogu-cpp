/**
 * @author OZLIINEX
 * @brief P1996 约瑟夫问题
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

// #define DEBUG
#define MAXN 1001
#define INF 0x3f3f3f3f
#define debug(...) fprintf(stdout,__VA_ARGS__)

typedef long long ll;
using namespace std;


int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

template<typename T>
inline void write(T x) {
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

int main()
{
    #ifdef DEBUG
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    clock_t start,finish;
    double totaltime;
    start = clock();
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    /*START*/

    int n = read(), m = read();
    bool vis[MAXN] = { false };

    int count_m = 0;
    int index = 0;
    int count_n = 0;

    while(1)
    {
        if(index == n) index = 0;
        index++;
        if(vis[index]) continue;
        count_m++;
        if(count_m == m)
        {
            count_m = 0;
            vis[index] = true;
            count_n++;
            writespace(index);
        }

        if(count_n == n) break;
    }

    putchar('\n');

    /*END*/

    #ifdef DEBUG
    finish = clock();
    totaltime = (double)(finish-start)/CLOCKS_PER_SEC*1000;
    printf("\n耗时: %.6lf ms\n",totaltime);
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}