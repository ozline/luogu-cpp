/**
 * @author OZLIINEX
 * @brief P2241 统计方形（数据加强版）
 * @date 2023-06-22
 */

#include <header.hpp>

ll anss = 0, anst = 0; // 正方形 全部答案

void solve()
{
    int n = read(), m = read();
    req(i, 1, n) req(j, 1, m)
    {
        anss += min(i, j);
        anst += i *j;
    }
    printf("%lld %lld", anss, anst - anss);
}


// 考虑一个2 * 3的矩阵
// 对于每一个点，它可以作为正方形的左上角
// 那么它可以作为正方形的边长为1,2,3的正方形的左上角
// 也就是说，对于每一个点，它可以作为边长为1,2,3的正方形的左上角