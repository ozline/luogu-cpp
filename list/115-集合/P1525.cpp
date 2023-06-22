/**
 * @author OZLIINEX
 * @brief P1525 [NOIP2010 提高组] 关押罪犯
 * @date 2023-01-24
 */

/**
 * 并查集的应用
 *
 * 首先读懂一下题目：给出犯人之间的怒气值，要求你把这一堆犯人放到两个监狱里，求两个监狱里影响力最小是多少（影响力指的是两个监狱里最大的怒气值）
 * 我们很自然的会想到：构建最小生成树，然后把最大的边去掉，剩下的边的最大值就是答案
 * 但是这样做的话，我们需要把所有的边都存下来，然后排序，然后再去掉最大的边，这样做的话，时间复杂度是O(n^2logn)，考虑到n = 20^4，这样做是不可行的
 *
 * 但是我们可以用最小生成树的思想：贪心
 * 我们可以构建一个strucrt{ int a, b, val; }; 表示a和b之间存在怒气值val
 * 我们对这个结构体数组按val从大到小排序，我们优先解决val大的边，这样我们就可以保证最后的答案是最小的
 * 怎么做呢？就是并查集！我们不需要去纠结确切的2个集合，下放到两个犯人之间，我们只需要保证这两个犯人不在一个监狱内，那么这个怒气值就不存在，这也是为什么我们要从大的开始处理
 * 我们设置一个数组enemy[i]，表示第i个犯人当前怒气值最大的敌人是谁
 * 然后我们直接开始遍历结构体数组，如果enemy[a] = 0，也就是还没有敌人，我们就把b放进去，如果enemy[a] != 0，说明a当前已经知道了一个最大的犯人c，那么我们只需要保证b和c在一个集合内就可以了
 * 因为，我们要知道，这个c如果和a放在一起，怒气值会比a和b放在一起更大，我们肯定要把这两个放在两个监狱，在看a和b，我们遍历到这个结构体，说明a和b的怒气值是当前最大的，我们也需要把这两个拆掉，那么很自然，b和c就要在一个监狱，所以我们利用并查集把b和c联起来
 *
 * 就这样遍历下去，一直到我们求到了一个结构体，我们发现这两个犯人a和b处于同一个监狱（因为并查集默认一开始每个犯人都是单独的监狱），说明这两个犯人不能拆开，我们可以思考一下为什么这两个犯人在同一个集合内，因为先前的遍历我们已经利用上文的理解把a（或者b）和另一个c拆开了，之所以拆开是因为他们两个不能在一个集合，否则a（或者b）和c的怒气值会更大
 * 也就是说，这时候这个val就是我们需要求的值，我们直接输出并跳出遍历即可
 * 当然，我们需要打一个tag，如果遍历到最后我们都没有出现这种情况，那么不就是说明答案是0吗？我们就输出0
 */

#include "header.hpp"
#define MAXN 200001

int fa[MAXN];
void set_init()
{
    req(i, 0, MAXN - 1) fa[i] = i;
}

int set_find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = set_find(fa[x]);
}

void set_union(int x, int y)
{
    if(set_find(x) != set_find(y))
    {
        fa[ fa[y] ] = fa[x];
    }
}

// 查找是否处于同一集合内
bool set_check(int x, int y)
{
    return set_find(x) == set_find(y);
}

struct Node
{
    int from, to, val; // from->to存在怒气值val
};

bool cmp(Node a, Node b)
{
    return a.val > b.val;
}

int n, m;
Node node[MAXN];
int enemy[MAXN];

void solve()
{
    bool temp = true;
    set_init();
    n = read(), m = read();
    req(i, 1, m)
    {
        // a 和 b 存在怒气值 c
        node[i].from = read();
        node[i].to = read();
        node[i].val = read();
    }

    sort(node + 1, node + 1 + m, cmp);

    req(i, 1, m)
    {
        if(set_check(node[i].from, node[i].to))
        {
            temp = false;
            writeln(node[i].val);
            break;
        }
        else
        {
            if(enemy[ node[i].from ] == 0) enemy[ node[i].from ] = node[i].to;
            else set_union(enemy[ node[i].from ], node[i].to);

            if(enemy[ node[i].to ] == 0) enemy[ node[i].to ] = node[i].from;
            else set_union(enemy[ node[i].to ], node[i].from);
        }
    }
    if(temp) puts("0");
}