/**
 * @author OZLIINEX
 * @brief P1147 连续自然数和
 * @date 2023-04-01
 */

// 秒杀的一道题，前缀和遍历即可

// 但是看题解，这道题可以数学优化：https://www.luogu.com.cn/blog/gzw2005/solution-p1147

#include "header.hpp"
#define MAXN 2000011

int m;
ll a[MAXN];

int l = 1;

void solve()
{
    m = read();

    req(i, 1, m) a[i] = a[i - 1] + i;

    req(i, 1, m) {
        if(a[i] - a[l] < (ll)m) continue;
        while(a[i] - a[l] > (ll)m) l++;
        if(a[i] - a[l] == (ll)m && l + 1 != i) printf("%d %d\n", l + 1, i);
    }
}

void solve_math()
{
    m = read();
    for(int k1 = sqrt(2 * m); k1 > 1; k1--)
    {
        if(2 * m % k1 == 0 && (k1 + 2 * m / k1) % 2)
        {
            int k2 = 2 * m / k1;
            printf("%d %d\n", (k2 - k1 + 1) / 2, (k1 + k2 - 1) / 2);
        }
    }
}