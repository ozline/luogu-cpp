/**
 * @author OZLIINEX
 * @brief P2678 [NOIP2015 提高组] 跳石头
 * @date 2023-03-27
 */

// 最大收获是那个check函数
// 这道题我一直不知道，如何获得，拆掉一个石头后，这段距离
// 他使用了一个一个for，然后留了一个last
// 如果我们要把这个石头拆走，那么cnt++，但不更新last
// 如果我们不拆这个石头，那么更新last为这个石头的距离
// 这时候判断的话，只需要计算a[i] - last < x就可以了
// 因为我们只需要关注目前一个石头的情况嘛

// 还是想复杂了

#include "header.hpp"
#define MAXN 60001

int l, n, m;
int a[MAXN], b[MAXN];

int lf = 1, ri = 0;

int ans;

bool check(int x)
{
    int last = 0, cnt = 0;
    req(i, 1, n)
    {
        if (a[i] - last < x) cnt++;
        else last = a[i];
    }

    if(l - last < x) cnt++; // 最后一块石头

    return cnt <= m;
}

void solve()
{
    l = read(), n = read(), m = read();

    req(i, 1, n)
    {
        a[i] = read();
        ri = max(ri, a[i] - a[i - 1]);
    }

    ri = max(ri, l - a[n]);

    // 考虑一下没有石头或者我们挪不动石头的情况，者应该是Subtask 3#和6#的情况
    if(m == 0 || n == 0)
    {
        printf("%d\n", ri);
        return;
    }

    while (lf + 1 < ri)
    {
        int mid = (lf + ri) >> 1;
        if (check(mid)) ans = lf = mid;
        else ri = mid;
    }

    printf("%d\n", ans);


    // 现在我们获取了每个石头之间的距离，我们想要的是去掉某些石头后，我们可以获得最短距离的最大值是多少
    // 那么我们可以这么写
    // 我们可以把每个石头之间的距离看成一个区间，然后我们去掉某些区间，那么我们就可以获得最短距离的最大值
    // 那么我们就可以二分答案，然后去判断是否可以去掉某些区间，使得最短距离不小于这个答案
}