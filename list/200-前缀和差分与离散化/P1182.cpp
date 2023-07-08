/**
 * @author OZLIINEX
 * @brief P1182 数列分段
 * @date 2022-12-04
 */

#include "header.hpp"
#define MAXN 100001


ll perfix[MAXN];

int n, m, a[MAXN];
int i, j;

void solve()
{
    n = read(), m = read();
    req(i,1,n) a[i] = read(), perfix[i] = perfix[i - 1] + a[i];

    return;
}