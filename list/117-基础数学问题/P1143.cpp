/**
 * @author OZLIINEX
 * @brief P1143 进制转换
 * @date 2023-04-09
 */

#include "header.hpp"
#define MAXN 500001


int n, m;       // n进制转m进制
string str;     // n进制数

void solve()
{
    cin >> n >> str >> m;

    int len = str.length();
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        int tmp = 0;
        if (str[i] >= '0' && str[i] <= '9')
            tmp = str[i] - '0';
        else
            tmp = str[i] - 'A' + 10;
        ans = ans * n + tmp;
    }

    string res = "";
    while (ans)
    {
        int tmp = ans % m;
        if (tmp >= 0 && tmp <= 9)
            res = (char)(tmp + '0') + res;
        else
            res = (char)(tmp - 10 + 'A') + res;
        ans /= m;
    }

    cout << res << endl;
}