/**
 * @file P1157.cpp
 * @author ozlinex
 * @brief P1157 组合的输出
 * @date 2023-07-09
 */

#include "header.hpp"
#include <iomanip>
#define MAXN 500001

ll n, r;
ll ans[MAXN], len;

void print()
{
    req(i, 0, r - 1) cout << setw(3) << ans[i];
    cout << endl;
}

void solve()
{
    cin >> n >> r;

    req(j, 0, n - r)
    {
        len = r; memset(ans, 0, sizeof(ans));
        req(i, 0, r) ans[i] = i + 1 + j; // 初始化
        while(len > 0)
        {
            print();
            len = r - 1;
            while(len >= 0 && ans[len] == n - r + len + 1) len--;
            if(len < 0) break;
            ans[len]++;
            req(i, len + 1, r) ans[i] = ans[i - 1] + 1;
        }
    }
}