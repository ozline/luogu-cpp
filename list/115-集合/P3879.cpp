/**
 * @author OZLIINEX
 * @brief P3879 [TJOI2010] 阅读理解
 * @date 2023-04-04
 */


// STL过了，不过我没记错的话当年应该是不能使用STL的，本质就是利用map模拟字典树

// 还有一件事，开了fastio后，cin和scanf混用会导致WA，要么只用cin，要么只用scanf，puts和printf同理
// 在洛谷上，似乎fastio后只能用cin和cout

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <ctime>
#include <stack>
#include <unordered_map>

#define MAXN 500001
#define INF 0x3f3f3f3f
#define INFLL 1LL<<60
#define writespace(a) write(a),putchar(' ')
#define writeln(a) write(a),putchar('\n')
#define req(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define fastio() std::ios::sync_with_stdio(false), std::cin.tie(0)

#ifdef DEBUG
    #define debug(...) fprintf(stdout,__VA_ARGS__)
    #define debugvar(a) cout<<"[DEBUG] "#a" = "<<a<<endl
#else
    #define debug(...) fun()
    #define debugvar(a) fun()
    void fun() { return; }
#endif

typedef long long ll;
typedef unsigned long long ull;
using namespace std;


inline int read() {
    int x = 0, w = 1; char ch = 0;
    while(ch < '0' || ch > '9') { if(ch == '-') w = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return(x * w);
}

inline void write(int x) {
    if(x == 0) { putchar('0'); return; }
    static int sta[35]; int top = 0;
    if(x<0) putchar('-'), x = -x;
    while(x) { sta[top++] = x % 10, x /= 10; }
    while(top) putchar(sta[--top] + 48);
}
/* END OF TEMPLATE */

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

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    fastio();
    solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}