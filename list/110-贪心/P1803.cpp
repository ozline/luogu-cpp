/**
 * @author OZLIINEX
 * @brief P1803 凌乱的yyy / 线段覆盖
 * @date 2023-03-29
 */

// 贪心，这个贪心感觉有必要写一下的
// 我一开始思考的是按持续时间排序，然后贪心开始时间最早的
// 写完过了例子后一交，好，爆零
// 后面想了一下，应该以结束时间来排序，我们尽可能的覆盖更多的区间

// 是的，我忘记这道题的标题了，覆盖区间
// 我们面对一排的区间，应当如何选择使得我们选择的区间不重复且数量最大？
// 当然是按结束时间来排啊，排完后我们模拟一个指针，从左到右扫描
// 每次扫描到一个区间，我们判断一下这个区间的开始时间是否大于指针的位置
// 大于的话就说明我们可以走这个区间，小于的话我们就跳过这个区间

#include "header.hpp"
#define MAXN 1001001

struct Node
{
    int l, r, dur; // 开始，结束，持续时间

    bool operator<(const Node &b) const
    {
        // if (dur == b.dur) return l < b.l;
        // return dur < b.dur;

        return r < b.r;
    }
};



int n;
Node a[MAXN];
int ans;

void solve()
{
    n = read();
    req(i, 1, n) a[i].l = read(), a[i].r = read(), a[i].dur = a[i].r - a[i].l;

    sort(a + 1, a + n + 1);

    int cur = 0;

    req(i, 1, n)
    {
        if (a[i].l >= cur)
        {
            cur = a[i].r;
            ans++;
        }
    }

    writeln(ans);
}