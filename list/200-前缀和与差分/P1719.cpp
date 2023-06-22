/**
 * @author OZLIINEX
 * @brief P1719 最大加权矩形
 * @date 2022-12-05
 */

#include "header.hpp"
#define MAXN 10001

int i, j, k, l;
int n, ans;
int a[MAXN][MAXN];
int dp[MAXN], temp[MAXN];


void solve()
{
    n = read();
    req(i, 1, n) req(j, 1, n) a[i][j] = read();

    req(i, 1, n)
    {
        memset(temp, 0, sizeof(temp));
        req(j, i, n)
        {
            req(k, 1, n) temp[k] += a[j][k];
            memset(dp, 0, sizeof(dp));
            req(l, 1, n)
            {
                dp[l] = max(dp[l], dp[l - 1] + temp[l]);
                ans = max(ans, dp[l]);
            }
        }
    }

    printf("%d", ans);

    return;
}