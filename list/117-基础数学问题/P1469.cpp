/**
 * @author OZLIINEX
 * @brief P1469 找筷子
 * @date 2023-04-02
 */

// 因为前置学习了，这道题蛮简单的
// 利用了 xor 的性质

#include "header.hpp"
#define MAXN 500001


int ans;

void solve()
{
    int n = read();
    req(i, 1, n) ans ^= read();
    writeln(ans);
}