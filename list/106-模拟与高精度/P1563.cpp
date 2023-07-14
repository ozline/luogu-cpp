/**
 * @file P1563.cpp
 * @author ozlinex
 * @brief P1563 [NOIP2016 提高组] 玩具谜题
 * @date 2023-07-14
 */

#include "header.hpp"
#define MAXN 500001

/*
0 = 朝内  1 = 朝外
0 = 左边  1 = 右边

默认逆时针排序

朝内左边 = 0 + 0 = 0 => -
朝内右边 = 0 + 1 = 1 => +
朝外左边 = 1 + 0 = 1 => +
朝外右边 = 1 + 1 = 2 => -
*/

int n, m;
int side[MAXN];
string name[MAXN];
int a, s;

int ans = 1;

void solve()
{
    cin >> n >> m;
    req(i, 1, n) cin >> side[i] >> name[i];
    req(i, 1, m)
    {
        cin >> a >> s;
        if((a + side[ans]) % 2) ans += s;
        else ans -= s;
        if(ans < 1) ans += n;
        if(ans > n) ans -= n;
    }
    cout << name[ans];
}