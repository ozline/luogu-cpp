/**
 * @author OZLIINEX
 * @brief P1827 [USACO3.4] 美国血统 American Heritage
 * @date 2023-01-10
 */

/**
 * 前序遍历：根左右
 * 中序遍历：左根右
 * 后序遍历：左右根
 *
 * e.g:
 * 中序遍历为：ABEDFCHG
 * 前序遍历为：CBADEFGH
 * 后序遍历为：AEFDBHGC
 *
 * 先看前序遍历，前序遍历中一个字符串的第一个字符一定是root
 * 那么我们根据这个root在中序遍历中定位它的位置，那么这个root的左右两边就是左右子树
 * 我们就可以继续递归搜索左和右，当然必须是先左后右，因为后序遍历是左右根
 *
 * 递归搜索完左和右，我们才输出root
 * 递归的结束条件就是Root的左右子树都为空(也就是说，传递的参数中的字符串为empty!)
 *
 * 这道题和P1030很像，但是P1030是中序遍历和后序遍历，这道题是前序遍历和中序遍历
 */

#include "header.hpp"
#define MAXN 500001

string a, b;

void work(string pre, string inor)
{
    if(pre.empty()) return;

    char root = pre[0];

    int k = inor.find(root);

    pre.erase(pre.begin()); // 删去根节点

    string pre_left = pre.substr(0, k);
    string pre_right = pre.substr(k);

    string inor_left = inor.substr(0, k);
    string inor_right = inor.substr(k + 1);

    work(pre_left, inor_left);
    work(pre_right, inor_right);

    printf("%c", root);
}

void solve()
{
    cin >> a >> b;
    work(b, a);
    return;
}