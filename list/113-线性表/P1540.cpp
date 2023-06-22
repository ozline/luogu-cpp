/**
 * @author OZLIINEX
 * @brief [NOIP2010 提高组] 机器翻译
 * @date 2023-01-07
 */

#include "header.hpp"
#define MAXN 1001

int m, n;
queue<int> Q;
int vis[MAXN];
int ans;

void solve()
{
    m = read(), n = read();
    req(i, 1, n)
    {
        int x = read();
        if (!vis[x])
        {
            if (Q.size() == m)
            {
                vis[Q.front()] = 0;
                Q.pop();
            }
            Q.push(x);
            vis[x] = 1;
            ans++;
        }
    }

    writeln(ans);
    return;
}