/**
 * @author OZLIINEX
 * @brief P4017 最大食物链计数
 * @date 2023-04-07
 */


// 本来是Vector存边，被我改成了链式前向星

// 结果链式前向星的边要开好大，最后5002 << 7过了，似乎是5002 * 128 = 640256
// 然后看了一下M的范围，果然

#include "header.hpp"
#define MAXN 5002

const int mod = 80112002;

int n, m, ans;
int in[MAXN], out[MAXN], sum[MAXN];

vector<int> nex[MAXN];
queue<int> q;


struct Node { int to, next; };

int head[MAXN], cnt;
Node edge[MAXN << 7];           // 这个Node要开好大
void add_edge(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void solve()
{
    req(i, 1, MAXN - 1) head[i] = -1;
    n = read(), m = read();
    req(i, 1, m)
    {
        int x = read(), y = read();
        in[y]++, out[x]++;
        add_edge(x, y);
    }

    req(i, 1, n) if(!in[i]) sum[i] = 1, q.push(i);

    while(!q.empty())
    {
        int now = q.front(); q.pop();

        for(int i = head[now]; i != -1; i = edge[i].next)
        {
            int next = edge[i].to;
            in[next]--; sum[next] = (sum[next] + sum[now]) % mod;
            if(in[next] == 0) q.push(next);
        }
    }

    req(i, 1, n) if(!out[i]) ans = (ans + sum[i]) % mod;

    printf("%d\n", ans);
}