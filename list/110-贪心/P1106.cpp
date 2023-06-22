/**
 * @author OZLIINEX
 * @brief P1106 删数问题
 * @date 2023-03-29
 */

// 数据蛮水的
// 思路其实蛮简单的，找规律就能发现，只要后一位比前面来的小，就直接删掉它，然后删k个就好了
// 可以发现时间复杂度比较大
// 感觉在更新数组这一部分可以优化
// 算了，过了就好，这道题花的时间太久了

#include "header.hpp"
#define MAXN 500001

int k;
int a[MAXN], len;

void solve()
{
    char ch = getchar();
    while(isdigit(ch))
    {
        a[++len] = ch - '0';
        ch = getchar();
    }

    k = read();

    req(i, 1, k)
    {
        req(j, 1, len)
        {
            if(a[j] > a[j + 1])
            {
                req(l, j, len) a[l] = a[l + 1];
                len--;
                break;
            }
        }
    }

    int idx = 1, l = 1;
    while(a[idx] == 0 && l <= len - 1) l++, idx++;

    req(i, l, len) printf("%d", a[i]);

}