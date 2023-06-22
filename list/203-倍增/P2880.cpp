/**
 * @author OZLIINEX
 * @brief P2880 [USACO07JAN] Balanced Lineup G
 * @date 2023-04-02
 */

// 这道题可以用线段树做，但是这是倍增题单里的
// 考虑到不会ST表，我抄了个题解来学习ST表

// ST表：sparse-table，是一个用于解决可重复贡献的问题的数据结构
// 例如，你想要一个多次查询某个区间内的最大值/最小值，就可以用ST表
// 关于ST表，可以看这个wiki：https://oi-wiki.org/ds/sparse-table/

// 倍增的代码意义我觉得可以表述为 maxn[i][k]，其中k表示2^k

#include "header.hpp"
#define MAXN 500001

int maxn[180010][22], minn[180010][22];
int n, m;


// 替代 std::log 函数
int logn[180010];
void init_log()
{
    logn[1] = 0;
    req(i, 2, 180000) logn[i] = logn[i >> 1] + 1;
}

// 查询[l, r]内最大值和最小值的差
// 其中查询最大值和查询最小值的可以直接背下来
int st(int l, int r)
{
    int s = logn[r - l + 1], x, y;
    x = max(maxn[l][s], maxn[r - (1 << s) + 1][s]); // 区间最大
    y = min(minn[l][s], minn[r - (1 << s) + 1][s]); // 区间最小

    return x - y;
}

void solve()
{
    init_log();
    n = read(), m = read();

    req(i, 1, n) maxn[i][0] = minn[i][0] = read();

    // 这里的21表示的是2^21，我们要保证这个上界比数据范围大
    req(i, 1, 21) req(j, 1, n - (1 << i) + 1)
    {
        // 可以直接背
        maxn[j][i] = max(maxn[j][i - 1], maxn[j + (1 << (i - 1))][i - 1]);
        minn[j][i] = min(minn[j][i - 1], minn[j + (1 << (i - 1))][i - 1]);
    }

    // 开始查询
    req(i, 1, m)
    {
        int l = read(), r = read();
        writeln(st(l, r));
    }
}