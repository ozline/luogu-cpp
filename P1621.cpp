/**
 * @file P1621.cpp
 * @author ozlinex
 * @brief P1621 集合
 * @date 2023-07-15
 */

// 题目蛮简短的：

#include "header.hpp"
#define MAXN 500001


int a, b, p, ans;
bool notPrime[MAXN];

int father[MAXN];

void set_init()
{
    req(i, 0, MAXN - 1) father[i] = i;
}

int set_find(int x)
{
    if(father[x] == x) return x;
    return father[x] = set_find(father[x]);
}

void set_merge(int x, int y)
{
    int fx = set_find(x), fy = set_find(y);
    if(fx != fy) father[fx] = fy;
}

void solve()
{
    cin >> a >> b >> p;
    ans = b - a + 1; // 答案初始化为a-b的个数

    set_init();

    req(i, 2, b)
    {
        if(!notPrime[i])
        {
            if(i >= p)
            {
                for(int j = i * 2; j <= b; j += i)
                {
                    notPrime[j] = true;
                    if(j - i >= a && set_find(j) != set_find(j - i))
                    {
                        set_merge(j, j - i);
                        ans--;
                    }
                }
            }
            else
            {
                for(int j = i * 2; j <= b; j+= i)
                {
                    notPrime[j] = true;
                }
            }
        }
    }

    cout << ans;
}