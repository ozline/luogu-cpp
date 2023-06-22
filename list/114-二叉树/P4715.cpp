/**
 * @author OZLIINEX
 * @brief P4715 【深基16.例1】淘汰赛
 * @date 2023-01-10
 */

#include "header.hpp"
#define MAXN 500001

struct Node
{
    int id, val;

    Node(int a, int b):id(a),val(b){};
};

int n;
queue<Node> q;
int ans;

void solve()
{
    n = read();
    n = 1 << n;
    req(i, 1, n) q.push(Node(i, read()));

    while(q.size() > 1)
    {
        Node a = q.front(); q.pop();
        Node b = q.front(); q.pop();
        if (a.val > b.val) q.push(Node(a.id, a.val)), ans = b.id;
        else if (a.val < b.val) q.push(Node(b.id, b.val)), ans = a.id;
    }

    printf("%d\n", ans);
    return;
}