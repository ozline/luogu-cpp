/**
 * @author OZLIINEX
 * @brief P271 选举学生会
 * @date 2022-12-05
 */
#include "header.hpp"
#define MAXN 2000001

int n, m;
int bucket[MAXN];

int i, j;

void solve()
{
    n = read(), m = read();
    req(i,1,m) bucket[i] = read();
    sort(bucket + 1, bucket + 1 + m);
    req(i,1,m) printf("%d ",bucket[i]);
    return;
}