/**
 * @author OZLIINEX
 * @brief P1177 【模板】快速排序
 * @date 2022-12-05
 */

#include "header.hpp"
#define MAXN 500001

int a[MAXN], n;

void quick_sort(int left, int right)
{
    int mid = a[ (left + right) >> 1];
    int i = left, j = right;
    while(i <= j)
    {
        while(a[i] < mid) i++;
        while(a[j] > mid) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    if(j > left) quick_sort(left, j);
    if(i < right) quick_sort(i, right);
}

void solve()
{
    n = read();
    req(i, 1, n) a[i] = read();
    quick_sort(1, n);
    req(i, 1, n) writespace(a[i]);
    return;
}