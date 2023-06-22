/**
 * @author OZLIINEX
 * @brief P3406
 * @date 2022-12-05
 */

/**
 * 来源于前缀和题单里的题，第一次的时候有点懵
 * 分析了一下发现只需要统计每一段的访问次数，然后再和售价一起计算一下就是最终结果
 * 因为每一段的售价只有2种情况
 *
 * 1.原价 * 访问次数
 * 2.折扣价 * 访问次数 + 卡价
 *
 * 接下来就是如何处理访问次数了
 * 第一次想到的是直接统计每一段的访问次数，提交后70分，T了2个点 WA了一个点
 * 考虑到可能是快读问题，去掉快读后各个点情况依旧
 * 分析一下可能导致超时的原因，发现是统计访问次数时使用while把经历的每一段都++
 * 如果出现大量的1->10^5和10^5->1，时间复杂度直接加起来了
 * 考虑一下昨天做题时的差分思想，把每一段旅程的头站++，尾站--
 * 然后处理前缀和就可以了
 * 然后就从T2 WA1 变到了 WA3..
 * 浪费了一次下载次数下载下来，一看out，明显超过int32了，把ans改成ll后提交还是如此
 * 然后尝试把cnt和vis数组都改成ll，就过了..
 */

#include "header.hpp"
#define MAXN 500001

int i,j;
int n, m;
int p[MAXN];
ll cnt[MAXN]; // 记录第i段铁路访问情况
ll vis[MAXN];

ll ans;

void solve()
{
    int from, to;
    int a, b, c;
    scanf("%d %d",&n,&m);
    req(i, 1, m)
    {
        scanf("%d",&p[i]);
        if(i == 1) continue;
        from = min(p[i], p[i - 1]), to = max(p[i], p[i - 1]);
        cnt[from]++, cnt[to]--;
    }

    req(i,1,n) vis[i] = vis[i - 1] + cnt[i];

    req(i, 1, n - 1)
    {
        scanf("%d %d %d",&a, &b, &c);
        ans += min(vis[i] * a, vis[i] * b + c);
    }

    printf("%lld",ans);
    return;
}