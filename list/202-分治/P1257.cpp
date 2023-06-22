/**
 * @author OZLIINEX
 * @brief P1257 平面上的最接近点对
 * @date 2022-12-27
 */

#include "header.hpp"
#define MAXN 10001

struct Node
{
    int x, y;
    double dist;
    Node():x(0),y(0){};
    Node(int a, int b):x(a),y(b){};

    double calDistance(const Node &obj) const
    {
        return sqrt((x - obj.x) * (x - obj.x) + (y - obj.y) * (y - obj.y));
    }

    void init()
    {
        x = read(), y = read();
        dist = (x * x + y * y);
    }

    bool operator<(const Node &obj) const
    {
        return dist < obj.dist;
    }
};

int n;
Node node[MAXN];
double ans = INF;



void solve()
{
    n = read();
    req(i, 1, n) node[i].init();

    sort(node + 1, node + n + 1);

    req(i, 1, n - 1)
    {
        req(j, i + 1, n)
        {
            if (node[j].dist - node[i].dist > ans) break;
            ans = min(ans, node[i].calDistance(node[j]));
        }
    }

    // req(i, 1, n)
    //     req(j, 1, n)
    //     {
    //         if(i == j) continue;
    //         ans = min(ans, node[i].calDistance(node[j]));
    //     }

    printf("%.4lf\n", ans);

    return;
}