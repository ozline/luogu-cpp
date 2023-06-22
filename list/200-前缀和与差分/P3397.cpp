/**
 * @author OZLIINEX
 * @brief P3397 地毯
 * @date 2022-12-05
 */

/**
 * 做前缀和题单的时候刷到的这道题
 * 做对这道题不是很难，因为数据给的实在是太小了
 * 但是如何应用前缀和呢？
 * 我们只需要在地毯的左边一列和右边一列打上记好即可
 * 例如这张图
 * 0 0 0 0 0 0
 * 0 +1 0 0 0 -1
 * 0 +1 0 0 0 -1
 * 0 +1 0 0 0 -1
 * 0 +1 0 0 0 -1
 * 0 0 0 0 0 0
 * 实际上就是对应了地毯（2，2）（5，5）的定义
 * 输出的时候只需要按行输出，行内进行前缀和就知道了
 */

#include "header.hpp"
#define MAXN 2001

int n, m;
int board[MAXN][MAXN];


void solve()
{
    int x1, x2, y1, y2;

    n = read(), m = read();

    while(m--)
    {
        x1 = read(), y1 = read(), x2 = read(), y2 = read();
        req(i,x1,x2) board[i][y1] ++, board[i][y2 + 1] --;
    }

    req(i, 1, n)
    {
        req(j, 1, n) printf("%d ",board[i][j] += board[i][j - 1]);
        putchar('\n');
    }
    return;
}