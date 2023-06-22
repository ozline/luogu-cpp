/**
 * @author OZLIINEX
 * @brief P1631 序列合并
 * @date 2022-07-26
 */

#include "header.hpp"
#define MAXN 500001

void solve()
{

    int n = read();
    int a[MAXN];
    // int b[MAXN];
    int num;

    priority_queue<int, vector<int>, greater<int> > Q;

    for(int i=1;i<=n;i++) a[i] = read();
    // for(int i=1;i<=n;i++) read(b[i]);

    bool flag = false;
    for(int i=1;i<=n;i++)
    {
        num = read();
        for(int j=1;j<=n;j++)
        {
            Q.push(a[j] + num);
            if( (i-2) * (j-2) > n) break;
        }

        //显然这么写是会T的，因为不需要动任何脑子(连我这种笨比都能2分钟内码出来)
        //注意！a[i]和b[i]是递增的！！
        /*
            假设现在Length = 8
            我问你！你觉得a[6] + b[6]可能是最小值吗！
            但是a[1] * b[6]还真有可能是最小值
            同理a[1] * b[8]也有可能是最小值
            这时候想一下，a[4] * b[4] 有没有可能是答案之一？
            如果是答案，那说明a[4] * b[3]也是答案，那说明a[4] * b[2]也是答案
            可以注意到这两个下标的乘积只要比一个数大那他俩必不可能是答案
            所以..

            我们只需要进行一些些剪枝就好了，那个i-2和j-2是我乱猜的（但是过了！）

            可能改成i-3和j-3也能过
        */
    }

    for(int i=1;i<=n;i++) writespace(Q.top()),Q.pop();
}