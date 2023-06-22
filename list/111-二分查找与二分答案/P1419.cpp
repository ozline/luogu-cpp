/**
 * @author OZLIINEX
 * @brief P1419 寻找段落
 * @date 2023-04-01
 */

// 在床上看这道题的时候发现好像思路蛮清晰的

// 就是单调队列 + 二分答案，没了！
// 核心还是，用单调队列忽略序号的问题
// 我们直接使用while(!q.empty() && q.top().idx + ... < ...) q.pop()就行了

// 230403： 调不动了，已经忘记了原代码的逻辑了，索性学习了一下优秀题解（其实是抄作业！

// 基本是发现了为啥上次失败了，因为特么perfix是ll而不是double
// 这道题就先这样闭关了，再写就不礼貌了

#include "header.hpp"
#define MAXN 500001

int n, s, t;
ll a[MAXN];
double l = -10000.0, r = 10000.0, mid, perfix[MAXN];

bool check(double x)
{
    req(i, 1, n) perfix[i] = perfix[i - 1] + double(a[i]) - x;

    int head = 1, tail = 0, q[MAXN];

    req(i, s, n)
    {
        while(head <= tail && perfix[q[tail]] > perfix[i - s]) tail--;
        q[++tail] = i - s;
        while(head <= tail && q[head] < i - t) head++;

        if(head <= tail && perfix[i] - perfix[q[head]] >= 0) return true;
    }

    return false;
}

void solve()
{
    scanf("%d%d%d", &n, &s, &t);
    req(i, 1, n)
    {
        scanf("%lld", &a[i]);
        perfix[i] = perfix[i - 1] + a[i];
    }

    while(r - l > 1e-5)
    {
        mid = (l + r) / 2.0;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.3lf\n", l);
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    // fastio();
    solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}