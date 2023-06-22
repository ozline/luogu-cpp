/**
 * @author OZLIINEX
 * @brief P1996 约瑟夫问题
 * @date 2022-07-25
 */

#include "header.hpp"
#define MAXN 1001

void solve()
{
    int n = read(), m = read();
    bool vis[MAXN] = { false };

    int count_m = 0;
    int index = 0;
    int count_n = 0;

    while(1)
    {
        if(index == n) index = 0;
        index++;
        if(vis[index]) continue;
        count_m++;
        if(count_m == m)
        {
            count_m = 0;
            vis[index] = true;
            count_n++;
            writespace(index);
        }

        if(count_n == n) break;
    }

    putchar('\n');
}