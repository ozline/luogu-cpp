/**
 * @file P1152.cpp
 * @author ozlinex
 * @brief P1152 欢乐的跳
 * @date 2023-07-11
 */

#include "header.hpp"
#define MAXN 500001

int a[MAXN], b[MAXN], cnt;
bool flag;

void solve()
{
    cin >> a[0];
    while(cin >> a[cnt])
    {
        if(cnt) b[cnt] = abs(a[cnt] - a[cnt - 1]);
        cnt++;
    }

    sort(b + 1, b + cnt);
    req(i, 1, cnt - 1)
    {
        if(b[i] != i) { flag = true; break; }
    }
    puts(flag ? "Not jolly" : "Jolly");
}