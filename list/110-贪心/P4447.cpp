/**
 * @author OZLIINEX
 * @brief P4447 [AHOI2018初中组]分组
 * @date 2023-03-28
 */

// 这道题最后是copy了热门题解
// 这道题做了好久..但其实不难
// 一直在纠结如何规避奇怪的分组，但是忽略了标题就是分组

// 思路其实很简单，我们可以假设(模拟?)出多个组
// 然后我们遍历数组，把新的数字插入合适的分组里即可，如果没有的话则新建一个
// 这里我们需要注意，我们对于每个分组，我们只需要它的最大值和组长
// 也就是说，我们没必要为每个分组开个stack，我们只需要用一个size[]和q[]即可
// 其中，size[]表示的是第i个数组的长度，q[]表示的是要加入这个分组，我们需要多大的能力
// 然后就是简单遍历
// 注意，由于我们期望的是尽可能的让组变长，因此遇到相同的组的时候，我们优先向短的那个组添加
// 观察代码可以发现，遇到实力相同的组，id靠前的组的长度永远不小于id靠后的组的长度

// 嗯。。题目就做完了，其实没有很难

#include "header.hpp"
#define MAXN 200001

int n;
int a[MAXN];
int ans = INF;
int siz[MAXN], cnt, q[MAXN];

void solve()
{
    n = read();
    req(i, 1, n) a[i] = read();
    sort(a + 1, a + 1 + n);


    req(i, 1, n)
    {
        int pos = lower_bound(q + 1, q + 1 + cnt, a[i]) - q;
        while(q[pos + 1] == a[i] && pos < cnt) pos++;

        if(pos > cnt || q[pos] != a[i]) siz[++cnt] = 1, q[cnt] = a[i] + 1;
        else siz[pos]++, q[pos]++;
    }

    req(i, 1, cnt) ans = min(ans, siz[i]);

    writeln(ans);
}