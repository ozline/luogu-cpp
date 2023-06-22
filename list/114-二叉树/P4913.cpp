/**
 * @author OZLIINEX
 * @brief P4913 【深基16.例3】二叉树深度
 * @date 2023-01-10
 */

// 二叉树模板题，好好学！

#include "header.hpp"
#define MAXN 500001

struct Node
{
    int left, right;
};

Node tree[MAXN];

int n, ans;

void dfs(int id, int deep)
{
    if(id == 0) return;
    ans = max(ans, deep);
    dfs(tree[id].left, deep + 1);
    dfs(tree[id].right, deep + 1);
}

void solve()
{
    n = read();
    req(i, 1, n) tree[i].left = read(), tree[i].right = read();
    dfs(1, 1);
    writeln(ans);
    return;
}