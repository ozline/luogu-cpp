/**
 * @author OZLIINEX
 * @brief P2234 [HNOI2002]营业额统计
 * @date 2023-01-09
 */

/**
 * 学习一下, set自带的lower_bound的时间复杂度大约为O(logN)
 * 而STL库中的lower_boun函数对set使用的话，时间复杂度为O(N)
 *
 * 查了一下:
 * 对于可随机访问的有序容器使用 algorithm 库中的 lower_bound 和 upper_bound 函数时间复杂度为O(logN)
 * 但对于set，multiset这种不能随机访问的有序容器，要用其自带的 lower_bound 和 upper_bound 的时间复杂度才为 O(logN)。
 *
 * lower_bound: 返回一个iterator，这个迭代器表示的是第一个不小于val的元素
 */

#include "header.hpp"
#define MAXN 32768

int n;
int current;
ll ans;
set<int> s;
set<int>::iterator it, temp;

void solve()
{
    n = read();
    s.insert(INF);
    s.insert(-INF);
    req(i, 1, n)
    {
        current = read();
        if(i > 1)
        {
            it = s.lower_bound(current);
            if(*it != current)
            {
                temp = it, temp--;
                ans+= min(abs(*it - current), abs(*temp - current));
            }
        }
        else ans += current;
        s.insert(current);
    }
    printf("%lld\n",ans);
    return;
}