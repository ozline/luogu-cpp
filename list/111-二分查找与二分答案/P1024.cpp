/**
 * @author OZLIINEX
 * @brief P1024 [NOIP2001 提高组] 一元三次方程求解
 * @date 2023-03-27
 */

// 上古NOIP的题似乎总是会遇到精度问题，很奇怪
#include "header.hpp"
#define MAXN 500001


double a, b, c, d;

double fun(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

void solve()
{
    double l, r, mid;
    cin >> a >> b >> c >> d;

    for(int i = -100; i < 100; i++)
    {
        l = i, r = i + 1;
        if(fun(l) == 0) { printf("%.2lf ", l); continue; }

        if(fun(l) * fun(r) < 0)
        {
            while(r - l >= 0.001)
            {
                mid = (l + r) / 2;
                if(fun(mid) * fun(r) <= 0) l = mid;
                else r = mid;
            }
            printf("%.2lf ", r);
        }
    }
}