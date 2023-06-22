/**
 * @author OZLIINEX
 * @brief P601 A+B Problem（高精）
 * @date 2022-12-15
 */

#include "header.hpp"
#define MAXN 1001


// 字符串翻转
void string_reverse(char *a)
{
    int len = strlen(a);
    req(i, 0, (len - 1) >> 1)
        swap(a[i], a[len - 1 - i]);
}

// 字符串交换
void string_swap(char *a, char *b)
{
    int len = max(strlen(a), strlen(b));
    req(i, 0, len - 1) swap(a[i], b[i]);
}

// 高精度加法(非负)
void cal_add(char *a, char *b, char *c)
{
    int lena = strlen(a), lenb = strlen(b);
    int len = max(lena, lenb), cf = 0;

    string_reverse(a), string_reverse(b);
    memset(c, 0, sizeof(char) * len);

    req(idx, 0, len - 1)
    {
        if(cf) c[idx] ++;
        if(idx < lena) c[idx] += (a[idx] - 48);
        if(idx < lenb) c[idx] += (b[idx] - 48);
        cf = c[idx] / 10;
        c[idx] %= 10;
        c[idx] += 48;
    }

    if(cf) c[len] = 49; // 独特进位
    string_reverse(c);
}

char a[MAXN], b[MAXN], c[MAXN];

void solve()
{
    cin >> a;
    cin >> b;
    cal_add(a, b, c);
    printf("%s\n", c);
    return;
}