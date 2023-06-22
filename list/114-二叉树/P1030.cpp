/**
 * @author OZLIINEX
 * @brief P1030 [NOIP2001 普及组] 求先序排列
 * @date 2023-01-14
 */

/**
 * 前序遍历：根左右
 * 中序遍历：左根右
 * 后序遍历：左右根
 *
 * 这道题与P1827异曲同工之妙
 * 但是这道题是中序遍历和后序遍历，P1827是前序遍历和中序遍历
 * 主要关注前序遍历结果和后序遍历结果，一个根在头一个根在尾
 */

#include "header.hpp"
#define MAXN 500001

void get_beford(string in, string after)
{
    if(in.size())
    {
        char ch = after[after.size() - 1];
        int k = in.find(ch);
        printf("%c", ch); // 输出根
        get_beford(in.substr(0, k), after.substr(0, k)); // 左子树
        get_beford(in.substr(k + 1), after.substr(k, in.size() - k - 1)); // 右子树
    }
}

string inord, aftord;

void solve()
{
    cin >> inord >> aftord;
    get_beford(inord, aftord);
    return;
}