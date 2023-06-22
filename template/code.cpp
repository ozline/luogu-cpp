/**
 * @author OZLIINEX
 * @brief 部分函数
 * @date 2022-07-29
 */

#include "header.hpp"
#define MAXN 100001

int n = MAXN; //这里指maxn
int a[MAXN]; //需要离散化数组
int b[MAXN];
void get_discretization()
{
    for(int i=1;i<=n;i++) a[i] = 1, b[i] = a[i]; //这里模拟读入
    sort(b+1,b+1+n);
    int length = unique(b+1,b+1+n) - (b + 1);
    for(int i=1;i<=n;i++)
    {
        int pos = lower_bound(b+1,b+1+length, a[i]) - b;
        a[i] = pos;
    }
}

int main()
{
    return 0;
}