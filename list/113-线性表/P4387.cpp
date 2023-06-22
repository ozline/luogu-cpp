/**
 * @author OZLIINEX
 * @brief P4387 【深基15.习9】验证栈序列
 * @date 2023-01-09
 */

/**
 * 其实就是模拟一个栈和一个队列
 *
 * pushed数组存放在数组a，poped数组则直接读入queue
 * 然后进行模拟，不断的往stack中push数组a的数
 * push完每个数后，我们进行判断，栈顶数字是否和queue.front()的一致
 * 如果一致的话则两边同时pop()，然后进行下一个匹配，一直到stack空或两个数字不匹配
 *
 * 最后判断一下queue是否为空就可以进行输出Yes或No了
 */

#include "header.hpp"
#define MAXN 100001

int q, n;
int a[MAXN], b[MAXN];

void solve()
{
    q = read();
    while(q--)
    {
        n = read();
        stack<int> s;
        queue<int> q;
        req(i, 1, n) a[i] = read();
        req(i, 1, n) q.push(read());
        req(i, 1, n)
        {
            s.push(a[i]);
            while(!s.empty() && s.top() == q.front())
            {
                s.pop();
                q.pop();
            }
        }

        puts(q.empty() ? "Yes" : "No");
    }
    return;
}