/**
 * @author OZLIINEX
 * @brief P1228 地毯填补问题
 * @date 2022-12-08
 */

/**
 * 分治题单内的题
 * 做题的时候由于提示明显，很明显能猜到是分治
 * 经过几次模拟，也可以发现是从大正方形到小正方形，一直一直慢慢解决
 * 但是我想不明白，比如2^3的图，那么中间那个应该如何安排，公主的位置该如何安排
 * 实际上这么填充的话永远会有一个格子填不了，这个格子就是公主的位置（在子正方形中就是多出来的空位）
 * 我们定义一个函数fun(ll x, ll y, ll a, ll b, ll l)
 * 其中(x,y)表示的是在这个正方形（没有确认尺寸）中那个格子的位置，而a, b表示我们当前所处正方形的
 * 左上角的坐标，这下子明白为什么solve()函数中调用fun是使用fun(x, y, 1, 1, len)了吧
 * 在每一次分治中，我们要确认这个正方形中点坐标，因此我们需要获取这个正方形的边长，也就是参数l
 * 那么a + mid不就是中点了吗？我们再根据这个来继续分治小正方形即可

 * 这道题从理论到实践于我而言是一个比较困难的过程，我在这部分卡了很久很久
 */

#include "header.hpp"
#define MAXN 500001

ll quick_power(ll a, ll b) // 快速幂
{
    ll ans = 1, base = a;
    while(b)
    {
        if(b & 1) ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}

int k, x, y;

ll len;

void fun(ll x, ll y, ll a, ll b, ll l)
{
    if(l == 1) return;
    ll mid = l >> 1;
    if(x <= a + mid - 1 && y <= b + mid - 1)
    {
        printf("%lld %lld 1\n",a + mid, b + mid);
        fun(x, y, a, b, mid);
        fun(a + mid - 1, b + mid, a, b + mid, mid);
        fun(a + mid, b + mid - 1, a + mid, b, mid);
        fun(a + mid, b + mid, a + mid, b + mid, mid);
    }
    else if(x <= a + mid - 1 && y > b + mid - 1)
    {
        printf("%lld %lld 2\n", a + mid, b + mid - 1);
        fun(a + mid - 1, b + mid - 1, a, b, mid);
        fun(x, y, a, b + mid, mid);
        fun(a + mid, b + mid - 1, a + mid, b, mid);
        fun(a + mid, b + mid, a + mid, b + mid, mid);
    }
    else if(x > a + mid - 1 && y <= b + mid - 1)
    {
        printf("%lld %lld 3\n", a + mid - 1, b + mid);
        fun(a + mid - 1, b + mid - 1, a, b, mid);
        fun(a + mid - 1, b + mid, a, b + mid, mid);
        fun(x, y, a + mid, b, mid);
        fun(a + mid, b + mid, a + mid, b + mid, mid);
    }
    else
    {
        printf("%lld %lld 4\n", a + mid - 1, b + mid - 1);
        fun(a + mid - 1, b + mid - 1, a, b, mid);
        fun(a + mid - 1, b + mid, a, b + mid, mid);
        fun(a + mid, b + mid - 1, a + mid, b, mid);
        fun(x, y, a + mid, b + mid, mid);
    }
}

void solve()
{
    k = read(), x = read(), y = read();
    len = quick_power(2, k);
    fun(x, y, 1, 1, len);
}