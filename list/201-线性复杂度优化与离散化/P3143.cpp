/**
 * @author OZLIINEX
 * @brief P3143 [USACO16OPEN] Diamond Collector S
 * @date 2023-04-01
 */


// 做的蛮久的，一开始用了单调队列，被这个题单坑了！
// 其实就是双指针题，不过其实也有难度

// 首先，我们既然知道双指针，那么大概率和perfix和suffix有关
// 我们可以利用一个遍历遍历出每个点i，左边可以取的最大数量，右边可以取的最大数量
// 然后我们合并计算就可以了

// 好，这个如何合并计算？
// 思考了很久，就又卡在这了

// 实际上，我们可以利用一点点DP思想，我们的perfix和suffix可以更改定义为
// perfix[i]: 点i左边的数组中，最大的连续子数组的长度
// suffix[i]: 点i右边的数组中，最大的连续子数组的长度
// 然后我们再用一个for加起来不就好了

// 思维提升了很多感觉

#include "header.hpp"
#define MAXN 500001
ll n, k;
ll a[MAXN];

ll l, r;

// 第i个点左边可以取的最大数量，第i个点右边可以取的最大数量
ll perfix[MAXN], suffix[MAXN];
ll ans;

void solve()
{
    n = read(), k = read();
    req(i, 1, n) a[i] = read();
    sort(a + 1, a + 1 + n);

    l = 1, r = n;
    req(i, 1, n)
    {
        while(a[i] - a[l] > k) l++;
        while(a[r] - a[n + 1 - i] > k) r--;

        perfix[i] = max(perfix[i - 1], i - l + 1);
        suffix[n + 1 - i] = max(suffix[n - i + 2], r - (n + 1 - i) + 1);
    }

    req(i, 1, n) ans = max(ans, perfix[i] + suffix[i + 1]);

    // debugvar(idxl);
    // debugvar(idxr);
    printf("%lld\n", ans);
}