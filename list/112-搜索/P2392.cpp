/**
 * @author OZLIINEX
 * @brief P2392 kkksc03考前临时抱佛脚 DFS
 * @date 2023-03-18
 */

#include "header.hpp"
#define MAXN 61


int s[5];
int a[65];


// 数据量太小，可以直接dfs
int ans = INF;
void dfs(int len, int now, int left, int right) {
    if(len < now)
    {
        ans = min(ans, max(left, right));
        return;
    }
    dfs(len, now + 1, left + a[now], right);
    dfs(len, now + 1, left, right + a[now]);
}

// 当然，我们也可以使用dp
int sum = 0;
int f[100001];
int work(int n)
{
    req(i, 1, 100001) f[i] = 0;

    req(i, 1, s[n])
    {
        for(int j = sum; j >= 0; j--)
        {
            if(f[j]) f[j + a[i]] = 1;
        }
    }

    int tmp = sum, res;
    req(i, 0, sum)
    {
        if(f[i] && tmp >= abs(i - (sum - i)))
        {
            tmp = abs(i - (sum - i));
            res = max(i, sum - i);
        }
    }

    return res;
}

void solve()
{
    int temp = 0;
    req(i ,1, 4) cin >> s[i];
    req(j, 1, 4)
    {
        ans = INF, sum = 0;

        req(i, 1, s[j]) cin >> a[i], sum+=a[i];
        // dfs(s[j], 1, 0, 0);
        ans = work(j);
        // debugvar(ans);

        temp += ans;
    }

    printf("%d\n", temp);

    return;
}