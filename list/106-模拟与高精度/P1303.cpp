/**
 * @author OZLIINEX
 * @brief P1303 A*B Problem
 * @date 2022-12-15
 */

#include "header.hpp"
#define MAXN 500001

/**
 * @brief 字符串翻转
 */
void string_reverse(char *a)
{
    int len = strlen(a);
    req(i, 0, (len - 1) >> 1)
        swap(a[i], a[len - 1 - i]);
}

/**
 * @brief 高精度乘法
 *
 * @param a 被乘数
 * @param b 乘数
 * @param c 结果
 * @return int 结果长度
 */
int cal_mul(char *a, char *b, int *c)
{
    int lena = strlen(a), lenb = strlen(b);
    int len = lena + lenb - 1, cf = 0;

    string_reverse(a), string_reverse(b);
    memset(c, 0, sizeof(char) * len);

    req(i, 0, lena - 1)
    {
        req(j, 0, lenb - 1)
            c[i + j] += (a[i] - '0') * (b[j] - '0');
    }

    // 处理进位
    req(idx, 0, len - 1)
    {
        if(cf) c[idx] += cf;
        cf = c[idx] / 10, c[idx] %= 10;
    }
    while(cf)
    {
        c[len] += cf;
        cf = c[len] / 10, c[len] %= 10;
        len++;
    }

    // 解决前导零，但保留零
    while(!c[len - 1] && len-- > 1);

    // c数组翻转
    req(i, 0, (len - 1) >> 1) swap(c[i], c[len - 1 - i]);

    return len;
}

char a[MAXN], b[MAXN];
int c[MAXN * 2 + 1], len;

void solve()
{
    cin >> a;
    cin >> b;
    len = cal_mul(a, b, c);
    req(i, 0, len - 1) putchar(c[i] + 48);
    return;
}