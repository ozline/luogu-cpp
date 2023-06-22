/**
 * @author OZLIINEX
 * @brief P3370 【模板】字符串哈希
 * @date 2023-01-23
 */


// 主要是prime, mod的使用和ull

#include "header.hpp"
#define MAXN 1000001


ull base = 131, prime = 1e9 + 7;
ull mod = 212370440130137957ull;
ull hashe(char *str)
{
    ull ans = 0;
    for(int i = 0; str[i]; i++)
    {
        ans = (ans * base + (ll)str[i]) % mod + prime;
    }
    return ans;
}

int n;
int ans;
char str[1501];
ull a[MAXN];

void solve()
{
    n = read();
    req(i, 1, n)
    {
        scanf("%s", str);
        a[i] = hashe(str);
    }
    sort(a + 1, a + 1 + n);
    ans = unique(a + 1, a + 1 + n) - a - 1;
    printf("%d\n", ans);
}