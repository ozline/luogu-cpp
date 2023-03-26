/**
 * @author OZLIINEX
 * @brief P1631 序列合并
 * @date 2022-07-26
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

int main()
{
    #ifdef DEBUG
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    clock_t start,finish;
    double totaltime;
    start = clock();
    #endif

    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);

    /*START*/

    int n;
    int a[MAXN];
    // int b[MAXN];
    int num;
    read(n);

    priority_queue<int, vector<int>, greater<int> > Q;

    for(int i=1;i<=n;i++) read(a[i]);
    // for(int i=1;i<=n;i++) read(b[i]);

    bool flag = false;
    for(int i=1;i<=n;i++)
    {
        read(num);
        for(int j=1;j<=n;j++)
        {
            Q.push(a[j] + num);
            if( (i-2) * (j-2) > n) break;
        }

        //显然这么写是会T的，因为不需要动任何脑子(连我这种笨比都能2分钟内码出来)
        //注意！a[i]和b[i]是递增的！！
        /*
            假设现在Length = 8
            我问你！你觉得a[6] + b[6]可能是最小值吗！
            但是a[1] * b[6]还真有可能是最小值
            同理a[1] * b[8]也有可能是最小值
            这时候想一下，a[4] * b[4] 有没有可能是答案之一？
            如果是答案，那说明a[4] * b[3]也是答案，那说明a[4] * b[2]也是答案
            可以注意到这两个下标的乘积只要比一个数大那他俩必不可能是答案
            所以..

            我们只需要进行一些些剪枝就好了，那个i-2和j-2是我乱猜的（但是过了！）

            可能改成i-3和j-3也能过
        */
    }

    for(int i=1;i<=n;i++) writespace(Q.top()),Q.pop();

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