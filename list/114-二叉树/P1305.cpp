/**
 * @author OZLIINEX
 * @brief P1305 新二叉树
 * @date 2023-01-21
 */

/**
 * 再来一遍..前序遍历 = 根左右
 *
 * 这道题对于理解前中后遍历有很大帮助
 * 比如原来是abc，现在对b扩展有bdi，也就是b的左儿子和右儿子是d和i
 * 那么我们为什么可以直接在b的后面插入di？
 * 考虑如下这个前序遍历：abdic
 * 而前序遍历在二叉树中的体现就是先把左边挖到底，到不能挖了再回退一格尝试挖右边
 * 以此类推可以发现，前序遍历就是直接在b后面插入di即可
 */

#include "header.hpp"
#define MAXN 500001

int n;
string str, temp;

void solve()
{
    cin >> n;
    cin >> str;
    req(i, 2, n)
    {
        cin >> temp;
        int x = str.find(temp[0]);
        str.erase(x, 1);
        str.insert(x, temp);
    }
    req(i, 0, str.size() - 1)
    {
        if(str[i] == '*') continue;
        cout << str[i];
    }
    return;
}