/**
 * @author OZLIINEX
 * @brief P1102 A-B 数对
 * @date 2023-01-24
 */

/**
 * 第一版我用了map来做的，但是做完看了一下题解发现有个双指针
 *
 * 我们先对数列进行排序，然后比如会变成 1 2 3 4 5
 * 我们定义一个left, r1, r2
 * 其中r1的下标表示的是(a[r1] - a[l]) <= c的最后位置的下一个
 * 而r2的下标表示的是(a[r2] - a[l]) < c的最后位置的下一个
 * 此时如果 a[r2] - a[l] == c && a[r1 - 1] - a[l] == c，那么这个区间内都是满足的，也就是ans += (r1 - r2)
 * 其实就是取刚好满足的多个B嘛..
 *
 * 时间复杂度应当为O(N)，因为每个数字都会被left遍历一遍，同时被两个right遍历一遍
 * 但是前面还有一个排序，快速排序平均时间复杂度是O(NlogN)，因此总共复杂度是O(NlogN)
 *
 * 我们可以思考一下为什么不能使用一个left和一个right呢？
 * 因为我们无法确定r2和r1区间内究竟有几个数字！如果存在数字，那还好办，那如果不存在数字呢？还要额外判断
 * 我们直接采用两个right来保证一个右端区间，这样维护一下这个区间就可以了
 *
 * 提升了很多！
 */

#include "header.hpp"
#define MAXN 200001

ll n, c;
ll a[MAXN], l, r1, r2;
ll ans;

void solve()
{
    int x;
    cin >> n >> c;
    req(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    l = r1 = r2 = 1;
    for(l = 1; l <= n; l++)
    {
        while(r2 <= n && a[r2] - a[l] < c) r2++;
        while(r1 <= n && a[r1] - a[l] <= c) r1++;
        if(a[r2] - a[l] == c && a[r1 - 1] - a[l] == c && r1 - 1 >= 1) ans+= (r1 - r2);
    }

    printf("%lld\n", ans);
    return;
}