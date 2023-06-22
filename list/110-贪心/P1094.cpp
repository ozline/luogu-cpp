/**
 * @author OZLIINEX
 * @brief P1094 [NOIP2007 普及组] 纪念品分组
 * @date 2023-03-29
 */


#include "header.hpp"
#define MAXN 500001

int w, n;
int a[MAXN];
int ans;

void solve()
{
    w = read(), n = read();
    req(i, 1, n) a[i] = read();
    sort(a + 1, a + 1 + n);

    int l = 1, r = n;
    while(l < r)
    {
        if(a[l] + a[r] <= w) l++, r--;
        else r--;
        ans++;
    }

    if(l == r) ans++;

    writeln(ans);
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    // fastio();
    solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}