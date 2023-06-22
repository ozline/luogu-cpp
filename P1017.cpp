/**
 * @author OZLIINEX
 * @brief P1017 [NOIP2000 提高组] 进制转换
 * @date 2023-04-11
 */

#include <header.hpp>
#define MAXN 500001
int n, r;
int ans[MAXN], cnt;

void solve()
{
    cin >> n >> r; cout << n << "=";

    int tr = abs(r); // 让模数永远是正的

    while(n != 0)
    {
        if(n < 0 || n % r == 0) ans[++cnt] = -r + n % r, n = n / r;
        else ans[++cnt] = n % r, n = n / r;
    }

    // output
    for(int i = cnt; i > 0; i--) cout << (ans[i] > 9 ? ans[i] - 10 + 'A' : ans[i]);

    cout<< "(base" << r << ")" << endl;
}