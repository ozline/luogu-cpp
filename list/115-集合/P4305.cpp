/**
 * @author OZLIINEX
 * @brief P4305 [JLOI2011]不重复数字
 * @date 2023-04-05
 */


// 又是训练STL的一天呢
// 这道题可以考虑学习一下平板电视（pbds），看看有没有时间学吧
// 用unordered_map水过了

#include "header.hpp"
#define MAXN 500001

int n, num, t;
unordered_map<int, int> mp;

void solve()
{
    t = read();
    while(t--)
    {
        mp.clear();
        n = read();
        req(i, 1, n)
        {
            num = read();
            if(mp[num]) continue;
            else
            {
                mp[num] = 1;
                writespace(num);
            }
        }
        putchar('\n');
    }
}