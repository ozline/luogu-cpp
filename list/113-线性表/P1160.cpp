
/**
 * @author OZLIINEX
 * @brief P1160 队列安排
 * @date 2023-01-04
 */

// STL List模板题！


#include "header.hpp"
#define MAXN 100001

int n, m;
list<int> l;
list<int>::iterator pos[MAXN], it;
int vis[MAXN];

void solve()
{
    n = read();

    l.push_front(1);
    pos[1] = l.begin();
    req(i, 2, n)
    {
        int k = read(), p = read();
        if(p == 0) pos[i] = l.insert(pos[k], i);
        else pos[i] = l.insert(next(pos[k]), i);
    }
    m = read();
    req(i, 1, m)
    {
        int x = read();
        if(vis[x]) continue;
        l.erase(pos[x]);
        vis[x] = true;
    }
    for(it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    return;
}