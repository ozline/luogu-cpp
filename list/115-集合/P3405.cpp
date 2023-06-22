/**
 * @author OZLIINEX
 * @brief P3405 [USACO16DEC]Cities and States S
 * @date 2023-01-23
 */

#include "header.hpp"

int n, ans;
map<string, int> mp;


ull base = 131, prime = 1e9 + 7;
ull mod = 212370440130137957ull;
ull hashe(char *str)
{
    ull ans = 0;
    for(int i = 0; str[i]; i++)
    {
        ans = (ans * base + (ll)str[i]) % mod + prime;
    }
    return ans;
}

void solve()
{
    string str1, str2;
    cin >> n;
    req(i, 1, n)
    {
        cin >> str1 >> str2;
        str1 = str1.substr(0, 2);
        if(str1 != str2) ans += mp[str1 + str2];
        mp[str2 + str1]++;
    }
    cout << ans << endl;
    return;
}