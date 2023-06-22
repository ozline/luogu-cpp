/**
 * @author OZLIINEX
 * @brief P2249 【深基13.例1】查找
 * @date 2023-03-26
 */

#include "header.hpp"
#define MAXN 2000001

int n, m;
int a[MAXN];

int find(int x)
{
    int l = 1, r = n;
    while(l < r && l >= 1 && r <= n)
    {
        int mid = (l + r) >> 1;
        if(a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if(a[l] != x) return -1;
    else
    {
        // 不需要下面这句话，遇到相同的数字，会在上述二分中不断逼近最左侧的
        // while((l - 1) >= 0 && a[l - 1] == x) l--;
        return l;
    }
}

void solve()
{
    n = read(), m = read();
    req(i, 1, n) a[i] = read();
    req(i, 1, m) writespace(find(read()));
    return;
}