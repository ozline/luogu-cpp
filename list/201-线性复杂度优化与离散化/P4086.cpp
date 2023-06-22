/**
 * @author OZLIINEX
 * @brief P4086 [USACO17DEC]My Cow Ate My Homework S
 * @date 2023-04-02
 */

// 没那么难，这道题看完题目思路基本就有了
// 就是处理几个前缀和，然后遍历（也是枚举）
// 不过是倒着处理，所以也可以叫后缀和？

// 需要注意的是，我们需要升序输出所有可能的k的值
// 也就是说，答案有时候不唯一
// 而且k不能为0！！

#include "header.hpp"
#define MAXN 500001

int n;
int a[MAXN];
int minx[MAXN]; // record the min value of a[i] in [i, n]
double avg[MAXN];  // record the average value of a[i] in [i, n]
int sum[MAXN];  // record the sum value of a[i] in [i, n]

double maxavg;
ll ans;

void solve()
{
    n = read();
    req(i, 1, n) a[i] = read();
    sum[n] = minx[n] = a[n];
    for(int i = n - 1; i > 0; i--)
    {
        minx[i] = min(minx[i+1], a[i]);
        sum[i] = sum[i + 1] + a[i];
    }

    for(int i = n - 1; i > 0; i--)
    {
        avg[i] = double(sum[i] - minx[i]) / (n - i);
        maxavg = max(maxavg, avg[i]);
    }

    req(i, 2, n)
    {
        // debug("avg[%d] = %lf, minx[%d] = %d, sum[%d] = %d\n", i, avg[i], i, minx[i], i, sum[i]);
        // 有个坑，有多个答案的时候，要每个都输出
        if(avg[i] == maxavg) printf("%d\n", i - 1);
    }
}