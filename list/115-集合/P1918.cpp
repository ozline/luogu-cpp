/**
 * @author OZLIINEX
 * @brief P1918 保龄球
 * @date 2023-01-24
 */

// ?? 太简单了点？

#include "header.hpp"
#define MAXN 500001

int n, q, x;
map<int, int> mp;

void solve()
{
    cin >> n;
    req(i, 1, n)
    {
        cin >> x;
        mp[x] = i;
    }
    cin >> q;
    while(q--)
    {
        cin >> x;
        cout << mp[x] << endl;
    }
    return;
}