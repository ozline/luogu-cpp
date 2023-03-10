/**
 * @author OZLIINEX
 * @brief P1801 黑匣子
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

/*

题解：这个gg不开放博客，那就贴个他id吧：https://www.luogu.com.cn/user/119261

实际上这道题我是不会做的，hx啊hx，做什么题都往线段树套，是不是只会线段树啊？
不对，我连线段树都学不好

这道题有2个套路，一个是对顶堆一个是平衡树，明儿好好认真学学平衡树

对顶堆：

oi-wiki:https://oi-wiki.org/ds/binary-heap/#_9

由两个堆组成的数据结构，可以类比成一个堆然后对称上去

下面的是大根堆，上面的是小根堆，小根堆元素均比任意大根堆元素大

注意这个题干，我们可以发现数据库中本身就是按升序排列，这不免让我们想到priority_queue（好吧我没想到）

对于每一个add操作，我们先把元素丢入大根堆里，然后从堆里一直取元素（ Q.top() ）到小根堆里一直到大根堆元素为i（也就是当前get下标），由于priority_queue的性质，我们可以发现这样子也满足对顶堆的性质（这半句话是copy的）

然后就是每一个get操作，注意到get操作后i会增1，我们先输出大根堆的根（ Q1.top() ），然后再从小根堆里移一个到大根堆里

然后这题就过啦

好晚了，明儿再学平衡树。。

顺手做做POJ3784，巩固一下对顶堆

其实这道题光看题解都看了半天，尤其是在脑内模拟对顶堆对样例的处理动画

*/


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

    priority_queue<int> Q;
    priority_queue<int, vector<int>, greater<int> > Q1;

    int m,n,q;
    int a[MAXN];
    int index = 1; //index维护入堆的下标，可以注意到index一直在递增
    read(m), read(n);

    for(int i=1;i<=m;i++) read(a[i]);
    for(int i=1;i<=n;i++)
    {
        read(q);
        for(int j=index;j<=q;j++) //这部分模拟ADD操作
        {
            Q.push(a[j]);
            if(Q.size() == i)
            {
                // debug("move %d to Q1\n",Q.top());
                Q1.push(Q.top());
                Q.pop();
            }
        }
        index = q + 1;
        writeln(Q1.top());
        Q.push(Q1.top());
        Q1.pop();
    }

    //题干条件说了一直递增

    //我们可以注意到


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