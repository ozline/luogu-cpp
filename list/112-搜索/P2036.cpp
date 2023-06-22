/**
 * @author OZLIINEX
 * @brief P2036 [COCI2008-2009#2] PERKET
 * @date 2023-03-26
 */

#include "header.hpp"
#define MAXN 500001

int n;
int s[MAXN], b[MAXN]; // sour, bitter;
int ans = INF;

void dfs(int idx, int sour, int bitter)
{
    if(sour != 0 || bitter != 0)
    {
        ans = min(ans, abs(sour - bitter));
    }
    if(idx > n) return;

    dfs(idx + 1, sour, bitter); // 不选这种
    dfs(idx + 1, (sour == 0 ? 1 : sour) * s[idx], bitter + b[idx]); // 选了这种
}

void solve()
{
    cin >> n;
    req(i, 1, n) cin >> s[i] >> b[i];
    dfs(1, 0, 0);

    printf("%d\n", ans);
    return;
}