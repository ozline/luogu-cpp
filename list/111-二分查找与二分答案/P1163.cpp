/**
 * @author OZLIINEX
 * @brief P1163 银行贷款
 * @date 2023-03-28
 */


// 这道题题目看了半天才懂，按月递增指的是这个月利率会每个月越来越大
// 所以会有一个公式，但是这里无法插入latex
// 公式的实现就是check()函数，当res * m = n时就是正确的利率
// 但是我们不需要那么正确，我们只需要求一个精度符合题意的即可

#include "header.hpp"
#define MAXN 500001

double n, m, k; // 贷款总额 每月还款 还款月份
double l, r;

bool check(double p)
{
    double res = 0, tmp = 1;
    req(i, 1, k)
    {
        tmp /= (1 + p);
        res += tmp;
    }

    return res >= (n / m);
}

void solve()
{
    n = read(), m = read(), k = read();
    l = 0, r = 50;
    while(r - l > 1e-6)
    {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.1lf", l * 100.0);


}