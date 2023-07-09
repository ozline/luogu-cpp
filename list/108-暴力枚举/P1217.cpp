/**
 * @file P1217.cpp
 * @author ozlinex
 * @brief P1217 [USACO1.5] 回文质数 Prime Palindromes
 * @date 2023-07-10
 */

// 结论：11是唯一的偶数位回文质数，其余的偶数回文数均不是质数（被11整除）
// 由此可知，只需要枚举奇数位回文数即可，同时超过1000万的不需要算

#include "header.hpp"
#define MAXN 500001

int a, b;

bool checkPalindromes(int x)
{
    int len = 0, num[20];
    while(x > 0)
    {
        num[len++] = x % 10;
        x /= 10;
    }

    if(len % 2 == 0) return false; // 判断位数

    for(int i = 0; i < len / 2; i++)
    {
        if(num[i] != num[len - i - 1]) return false;
    }
    return true;
}

bool checkPrime(int x)
{
    if(x == 1) return false;
    if(x == 2) return true;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

void solve()
{
    int a = read(), b = min(9999999, read());
    if(a % 2 == 0) a++;
    for(int i = a; i <= b; i+=2)
    {
        if(i == 11) printf("11\n");
        if(checkPalindromes(i) && checkPrime(i)) printf("%d\n", i);
    }
}