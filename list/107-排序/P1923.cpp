/**
 * @author OZLIINEX
 * @brief P1923 第k小的数
 * @date 2022-12-15
 */

/**
 * 我们以{4, 3, 2, 1, 5}为例(下标从1开始)
 * 我们经过第一轮快排后，可以发现数字变为了
 * {1, 3, 2, 4, 5} i = 2, j = 3
 * {}
 */

#include "header.hpp"
#define MAXN 5000005

int n, k;
int a[MAXN];

void quick_sort(int left, int right)
{
    int i = left, j = right, mid = a[(left + right) / 2];

    while(i <= j)
    {
        while(a[i] < mid) i++;
        while(a[j] > mid) j--;
        if(i <= j)
        {
            // a[i] ^= a[j], a[j] ^= a[i], a[i] ^= a[j];
            swap(a[i], a[j]);
            i++, j--;
        }
    }

    if(k <= j) quick_sort(left, j);
    else if(k >= i) quick_sort(i, right);
    else
    {
        printf("%d", a[j + 2]);
    }
}

void solve()
{
    n = read(), k = read();
    req(i, 1, n) a[i] = read();
    quick_sort(1, n);
    return;
}