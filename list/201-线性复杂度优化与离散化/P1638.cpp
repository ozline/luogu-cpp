/**
 * @author OZLIINEX
 * @brief P1638 逛画展
 * @date 2023-04-01
 */

// 在一个很神奇的地方卡住了，其实没有很难
// 二分l和r后，根据我的逻辑应该再check一下l，以更新ans
// 然后我一直没更新，就卡着了

#include "header.hpp"
#define MAXN 1000001

int n, m;
int a[MAXN];
queue<int> q;
int cnt[MAXN], vis; //记录访问次数

// 确定范围
int l, r, mid;

int ans;

bool check(int x)
{
    vis = 0, ans = 1;
    memset(cnt, 0, sizeof(cnt));
    while(!q.empty()) q.pop();

    for(; ans <= n; ans++)
    {
        q.push(a[ans]);
        if(cnt[ a[ans] ] == 0) vis++;
        cnt[ a[ans] ]++;

        while(!q.empty() && q.size() > x)
        {
            cnt[q.front()]--;
            if(cnt[q.front()] == 0) vis--;
            q.pop();
        }

        debug("vis = %d, m = %d\n\n", vis, m);

        if(vis == m) break;
    }
    return vis == m;
};

void solve()
{
    n = read(), m = read();
    req(i, 1, n) a[i] = read();
    l = 0, r = n;
    while(l < r)
    {
        mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    check(l);
    printf("%d %d\n", ans - l + 1, ans);
}