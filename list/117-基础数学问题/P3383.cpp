/**
 * @author OZLIINEX
 * @brief P3383 【模板】线性筛素数
 * @date 2022-07-28
 */

#include "header.hpp"
#define MAXN 100000001

int Prime[MAXN];
bool vis[MAXN];
int cnt = 0;

void solve()
{
    int n = read(), q = read();
    for(int i=2;i<=n;i++)
    {
        if(vis[i] == false)  Prime[++cnt] = i;

        for(int j=1; j<=cnt; j++)
        {
            if( i * Prime[j] > n) break;
            vis[ i * Prime[j] ] = true;
            if( i % Prime[j] == 0 ) break;
        }
    }

    while(q--) writeln(Prime[read()]);
}