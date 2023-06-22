/**
 * @author OZLIINEX
 * @brief P3879 [TJOI2010] 阅读理解
 * @date 2023-04-04
 */


// STL过了，不过我没记错的话当年应该是不能使用STL的，本质就是利用map模拟字典树

// 还有一件事，开了fastio后，cin和scanf混用会导致WA，要么只用cin，要么只用scanf，puts和printf同理
// 在洛谷上，似乎fastio后只能用cin和cout

#include "header.hpp"
#define MAXN 500001

int n, m, l;
string s;

map<string, set<int> > mp;

void solve()
{
    cin >> n;
    req(i, 1, n)
    {
        cin >> l;
        req(j, 1, l)
        {
            cin >> s;
            mp[s].insert(i);
        }
    }

    cin >> m;
    while(m--)
    {
        cin >> s;
        if(mp.count(s))
        {
            for(set<int>::iterator it = mp[s].begin(); it != mp[s].end();)
                cout << *it << (++it == mp[s].end() ? "" : " ");
        }

        cout << endl;
    }
}