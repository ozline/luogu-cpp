/**
 * @author OZLIINEX
 * @brief [NOIP2005 普及组] 采药
 * @date 2023-04-07
 */

#include "header.hpp"
#define MAXN 500001

struct Node
{
    int consume; //消耗的时间
    int value; //草药价值
};

int t, m;
Node node[MAXN];
int dp[MAXN];       //表示有多少钱时的最优解


int f[MAXN][MAXN]; // f[i][j] 表示采第i株药，花费时间j可以采集到的草药的最大价值

/*
    不采摘第i株     f[i][j] = f[i - 1][j]
    采摘第i株       f[i][j] = max(f[i][j], f[i - 1][j - t[i]] + pri[i])

    我们还有dp[i]，表示花费的时间j时，可以采摘到的草药的最大价值
*/


void solve()
{
    t = read(), m = read();

    for(int i=1;i<=m;i++)
    {
        node[i].consume = read();
        node[i].value = read();
    }

    // i表示第i种草药
    for(int i=1;i<=m;i++)
    {
        // j表示花费时间j来采摘草药
        for(int j=t;j>=node[i].consume;j--)
        {
            // 花费时间j可以采摘到的最大价值 = max(不采摘当前草药的最大价值 + 当前草药价值, 当前花费解)
            dp[j] = max(dp[j - node[i].consume] + node[i].value,dp[j]);
        }
    }

    writeln(dp[t]);
}