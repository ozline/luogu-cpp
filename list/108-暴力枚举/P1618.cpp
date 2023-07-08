/**
 * @file P1618.cpp
 * @author ozlinex
 * @brief P1618 三连击（升级版）
 * @date 2023-06-23
 */

// 本质是枚举，直接枚举第一个数，然后计算出剩下两个数，判断是否达标
// 这里面有个最重要的，就是我们要确保每个数字只出现一次

#include "header.hpp"
#define MAXN 500001

void solve()
{
    int a = read(), b = read(), c = read();
    int sum = 0;

    if(a == 0 || b == 0 || c == 0)
    {
        cout << "No!!!" << endl;
        return;
    }

    req(i, 123, 987)
    {
        int j = i * b / a, k = i * c / a;

        if(j > 987 || k > 987) continue;
        if(j < 123 || k < 123) continue;
        if(i * b != j * a) continue;
        if(i * c != k * a) continue;
        if(i % 10 == 0 || j % 10 == 0 || k % 10 == 0) continue;

        int cnt[10] = { 0 };
        cnt[i / 100]++; cnt[i / 10 % 10]++; cnt[i % 10]++;
        cnt[j / 100]++; cnt[j / 10 % 10]++; cnt[j % 10]++;
        cnt[k / 100]++; cnt[k / 10 % 10]++; cnt[k % 10]++;

        bool flag = true;
        req(i, 1, 9) if(cnt[i] != 1) flag = false;

        if(flag)
        {
            sum++;
            cout << i << " " << j << " " << k << endl;
        }
    }

    if(sum == 0) cout << "No!!!" << endl;
}