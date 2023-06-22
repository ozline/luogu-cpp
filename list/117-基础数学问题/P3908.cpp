/**
 * @author OZLIINEX
 * @brief P3908 数列之异或
 * @date 2023-04-02
 */

// 推广

// 考虑0、1、2、3
// 也就是00、01、10、11
// 这四个异或完就是0
// 所以我们判断一下n和4的关系即可

#include "header.hpp"
#define MAXN 500001

ll n;
ll ans;


void solve()
{
    scanf("%lld", &n);
    if(n % 4 == 1) ans = 1;
    if(n % 4 == 2) ans = n + 1;
    if(n % 4 == 3) ans = 0;
    if(n % 4 == 0) ans = n;

    printf("%lld\n", ans);
}