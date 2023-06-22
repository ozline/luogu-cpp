/**
 * @author OZLIINEX
 * @brief P1522 [USACO2.4] 牛的旅行 Cow Tours
 * @date 2022-12-19
 */

/**
 * 题目比较复杂，分析一下
 * 一个农场的直径 = 这个农场中最远的两个点之间的直线距离
 * 首先看到 N = 150，判断是floyd最短路，通过floyd可以得到：图上任意两点之间的最短路
 * 但是对于题目所给的数据，我们并不知道任意一个点是属于A农场还是属于B农场，因此我们需要对点进行标记，这部分使用dfs
 * 我们还不知道每个农场的直径，那么我们就需要枚举出最长的距离，考虑到N很小，直接N^2枚举即可
 *
 * 梳理一下，现在我们有： 两个农场的直径、每个点所属的农场id、任意两点之间的距离
 *
 * 接下来我们需要枚举那个新的边，并且构成一个大农场，那么就是从两个农场中分别枚举一个点，标记为a和b
 * 我们需要知道a点和b点之间的距离、这样加上两个点分别的最远距离，我们就可以得到新农场的直径（情况1:这两个农场不是包含关系）
 * 也就是说，这个新的直径可以表示为: d_temp = dis(a, b) + maxlen[a] + maxlen[b]
 * 其中maxlen[i]表示的是从i点出发能够到达的最远距离
 *
 * 那么如何计算这个maxlen[i]呢？
 * 注意maxlen[i]的定义和本题数据范围，我们只需要遍历所有点，对每个点遍历其他点，如果maxlen[i] <= dis[i][j]，那么就更新maxlen[i]
 * 也就是maxlen[i] = max(maxlen[i], dist[i][j])，但是要注意，这里的j点是有条件的:i和j要连通
 *
 * 接下来我们要考虑，可能农场A和农场B是包含关系呢？比如A包含B(B包含A)，那么我们新的农场的直径就不是上面的计算结果了
 * 而且很明显，上面的计算结果是小于这种情况下的A农场直径或B农场的直径的，这种情况下新农场的直径就是A农场直径或B农场直径
 *
 * 设计算结果为d_temp，A农场直径为d_a，B农场直径为d_b
 * 那么我们对于每一次枚举，实际上得到的新农场的直径应该是 : d_new = max(d_temp, d_a, d_b)
 */

#include "header.hpp"
#define MAXN 151

struct Node
{
    int x, y, field;
    Node():x(0),y(0),field(0){};
    Node(int a, int b):x(a), y(b), field(0){};

    double calDistance(const Node& b) const
    {
        return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }

    void init() { x = read(), y = read(); }
};

int n;
double dist[MAXN][MAXN], d[3], maxd;
Node node[MAXN];


void floyd()
{
    req(k, 1, n)
    {
        req(i, 1, n)
            req(j, 1, n)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
}

void dfs(int i, int id)
{
    node[i].field = id;

    // 未访问过的则继续访问
    req(j, 1, n) if(node[j].field == 0 && dist[i][j] < INF) dfs(j, id);

}

void solve()
{
    n = read();
    req(i, 1, n) node[i].init();

    char ch = 0;
    req(i, 1, n)
    {
        req(j, 1, n)
        {
            while (ch != '0' && ch != '1') ch = getchar();
            dist[i][j] = (ch == '1' || i == j) ? node[i].calDistance(node[j]) : INF;
            ch = 0;
        }
    }

    // 对点进行染色标记所属农场
    int id = 1;
    req(i, 1, n) if(node[i].field == 0) dfs(i, id++);
    // req(i, 1, n) debug("x: %d , y: %d, field: %d\n",node[i].x, node[i].y, node[i].field);

    // 获得最短路
    floyd();

    // 获得每个点到其他连通点的最长路径长度，并更新农场直径
    double maxlen[MAXN] = { 0.0 };
    req(i, 1, n)
    {
        req(j, 1, n) if(dist[i][j] < INF) maxlen[i] = max(maxlen[i], dist[i][j]);
        d[ node[i].field ] = max(d[ node[i].field ], maxlen[i]); // 更新农场直径
    }
    maxd = max(d[1], d[2]);

    // 计算答案
    double temp, ans = INF;
    req(i, 1, n)
    {
        req(j, i + 1, n)
        {
            if(node[i].field != node[j].field)
            {
                temp = max(maxd, maxlen[i] + node[i].calDistance(node[j]) + maxlen[j]);
                ans = min(ans, temp);
                // if(max_dist < min_dist)
                // {
                //     min_dist = max_dist;
                //     debug("connect: %d to %d get new D: %lf\n", i, j, min_dist);
                //     debug("i x: %d , y: %d, field: %d\n",node[i].x, node[i].y, node[i].field);
                //     debug("j x: %d , y: %d, field: %d\n",node[j].x, node[j].y, node[j].field);
                //     debugvar(maxlen[i]), debugvar(maxlen[j]), debugvar(node[i].calDistance(node[j]));
                // }
            }
        }
    }

    printf("%.6lf\n", ans);

    return;
}