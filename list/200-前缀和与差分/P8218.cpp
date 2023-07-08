/**
 * @file P8128.cpp
 * @author ozlinex
 * @brief P8218 【深进1.例1】求区间和
 * @date 2023-07-08
 */

#include "header.hpp"
#define MAXN 500001

int n, m;
ll perfix[MAXN];

void solve()
{
    n = read();
    req(i, 1, n) perfix[i] = perfix[i - 1] + read();
    m = read();
    req(i, 1, m)
    {
        int l = read(), r = read();
        printf("%lld\n", perfix[r] - perfix[l - 1]);
    }
}