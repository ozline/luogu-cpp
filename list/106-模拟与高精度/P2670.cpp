/**
 * @file P2670.cpp
 * @author ozlinex
 * @brief P2670 [NOIP2015 普及组] 扫雷游戏
 * @date 2023-07-14
 */

#include "header.hpp"
#define MAXN 101

int n, m;
string tmp;
int a[MAXN][MAXN]; // 1 = 地雷 0 = 不是地雷
int ans[MAXN][MAXN];

void solve()
{
    cin >> n >> m;
    req(i, 1, n)
    {
        cin >> tmp;
        req(j, 0, tmp.length() - 1)
        {
            a[i][j + 1] = tmp[j] == '*' ? 1 : 0;
        }
    }

    req(i, 1, n) req(j, 1, m)
    {
        int res = 0;
        if(a[i][j] == 0)
        {
            if(i > 1 && a[i - 1][j]) res++;
            if(j > 1 && a[i][j - 1]) res++;
            if(i > 1 && j > 1 && a[i - 1][j - 1]) res++;
            if(i < n && a[i + 1][j]) res++;
            if(j < n && a[i][j + 1]) res++;
            if(i < n && j < n && a[i + 1][j + 1]) res++;
            if(i > 1 && j < n && a[i - 1][j + 1]) res++;
            if(i < n && j > 1 && a[i + 1][j - 1]) res++;
            ans[i][j] = res;
        }
        else ans[i][j] = -1;
    }

    req(i, 1, n)
    {
        req(j, 1, m)
        {
            if(ans[i][j] == -1) cout << '*';
            else cout << ans[i][j];
        }
        cout << endl;
    }
}