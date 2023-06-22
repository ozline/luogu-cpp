/**
 * @author OZLIINEX
 * @brief P5250 【深基17.例5】木材仓库
 * @date 2023-01-24
 */

/**
 * 这道题是看题解改的
 * 还是对STL不习惯，我自己写的版本是map + set，后面发现只需要set
 * 有如下注意点：
 * 1. set自带的lower_bound(x)返回不小于x的第一个迭代器
 * 2. set自带的upper_bound(x)返回【不小于x】的【最后一个】迭代器
 * 3. set.insert(x)会返回一个pair<iterator, bool>，其中iterator指向插入的元素，bool表示是否插入成功
 *
 * 这道题这三个点用了两个，我自己写的版本卡了很久的第二个点，受教了
 */

#include "header.hpp"
#define MAXN 500001

int n;
set<int> s;
set<int>::iterator it, temp;

void solve()
{
    int op, x;
    // n = read();
    scanf("%d", &n);
    req(i, 1, n)
    {
        // op = read(), x = read();
        scanf("%d%d", &op, &x);
        if(op == 2)
        {
            if(s.empty()) puts("Empty");
            else
            {
                it = s.find(x);
                if(it != s.end()) printf("%d\n", x), s.erase(it);
                else
                {
                    it = s.lower_bound(x);
                    temp = it, temp--;
                    if(it == s.begin()) printf("%d\n", *it), s.erase(it);
                    else if(it == s.end()) printf("%d\n", *temp), s.erase(temp);
                    else if(*it - x < x - *temp) printf("%d\n", *it), s.erase(it);
                    else printf("%d\n", *temp), s.erase(temp);
                }
            }
        }
        else if(!s.insert(x).second) puts("Already Exist");
    }
    return;
}