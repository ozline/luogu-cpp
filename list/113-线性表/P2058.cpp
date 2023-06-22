/**
 * @author OZLIINEX
 * @brief [NOIP2016 普及组] 海港
 * @date 2023-01-08
 */

#include "header.hpp"
#define MAXN 100001

struct Node
{
    int t, k;
    vector<int> v;
};

int n, t, k;
queue<Node> Q;
int cnt[MAXN], ans;
vector<int>::iterator it;

void solve()
{
    n = read();
    req(i, 1, n)
    {
        Node temp;
        temp.t = read(), temp.k = read();
        while(!Q.empty())
        {
            Node node = Q.front();
            if(node.t + 86400 <= temp.t)
            {
                Q.pop();
                for(it = node.v.begin(); it != node.v.end(); it++)
                {
                    cnt[*it]--;
                    if(cnt[*it] == 0) ans--;
                }
            }
            else break;
        }

        req(j, 1, temp.k)
        {
            int x = read();
            temp.v.push_back(x);
            if(cnt[x] == 0) ans++;
            cnt[x]++;
        }
        Q.push(temp);
        writeln(ans);
    }
    return;
}