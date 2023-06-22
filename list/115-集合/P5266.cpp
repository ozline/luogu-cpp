/**
 * @author OZLIINEX
 * @brief P5266 【深基17.例6】学籍管理
 * @date 2023-01-24
 */
#include "header.hpp"
#define MAXN 500001

int n, op;
ull x;
string name;
unordered_map<string, ull> mp;
unordered_map<string, ull>::iterator it;

void solve()
{
    cin >> n;
    while(n--)
    {
        cin >> op;
        if(op == 1) // 插入与修改
        {
            cin >> name >> x;
            mp[name] = x;
            puts("OK");
        }
        else if(op == 2) // 查询
        {
            cin >> name;
            if(mp.count(name) == 0) puts("Not found");
            else cout << mp[name] << endl;
        }
        else if(op == 3) // 删除
        {
            cin >> name;
            if(mp.count(name) == 0) puts("Not found");
            else mp.erase(mp.find(name)), puts("Deleted successfully");
        }
        else if(op == 4) // 汇总
        {
            cout << mp.size() << endl;
        }
    }
    return;
}