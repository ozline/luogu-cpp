/**
 * @author OZLIINEX
 * @brief P1364 医院设置
 * @date 2023-01-20
 */

/**
 * 标准答案，O(n)解法，认真学习了
 * 这道题大多数解法是用floyd，但是这道题被放在了二叉树题单里
 * 用floyd有点尴尬，不过考虑到这道题的输入情况，我们构建一个二叉树并不是一个好办法
 * 我们选用链式前向星建边
 *
 * 这里参考了题解中的一个优秀答案，我们定义f[i]为以i为根的总距离，size[i]为以i为根的子树的大小
 * 我在前几天成功实现了动态开点的二叉树，这次我用静态的
 * 实际上，ans = min(f[1] + ... + f[n])
 * 我们需要做的就是如何更新f[i]，注意到对于每个i能到达的点v，有
 * f[v] = f[i] + size[1] - size[v] - size[i]
 *
 * 试想，当根从i变为v的时候，v的子树的所有节点原本的距离要到u，现在只要到v了，每个结点的距离都减少1，那么总距离就减
 * 少了size[v]，而其他节点的距离都增加了1，那么总距离就增加了size[1] - size[v]
 * 因此，(总增加 - 总减少)我们就可以知道转移成本了
 *
 * 不过我们需要进行预处理，也就是获取size[1]和f[i]
 */

#include "header.hpp"
#define MAXN 10001

// 链式前向星
struct Edge
{
    int next;
    int to;
};
int head[MAXN], cnt;
Edge edge[MAXN << 1];

void edge_add(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int n;
ll siz[MAXN], f[MAXN], w[MAXN];
ll ans = INFLL;

void dfs(int u, int fa, int depth)
{
    siz[u] = w[u];
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v == fa) continue;
        dfs(v, u, depth + 1);
        siz[u] += siz[v];
    }
    f[1] += w[u] * depth;
}

void dp(int u, int fa)
{
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v == fa) continue;
        f[v] = f[u] + siz[1] - siz[v] * 2;
        dp(v, u);
    }
    ans = min(ans, f[u]);
}

void solve()
{
    int u, v;
    req(i, 0, MAXN - 1) head[i] = -1; // 预处理
    n = read();
    req(i, 1, n)
    {
        w[i] = read(), u = read(), v = read();
        if(u != 0) edge_add(i, u), edge_add(u, i);
        if(v != 0) edge_add(i, v), edge_add(v, i);
    }
    dfs(1, 0, 0);
    dp(1, 0);
    printf("%lld\n", ans);
    return;
}