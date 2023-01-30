/**
 * @author OZLIINEX
 * @brief P2814 家谱
 * @date 2023-01-30
 */

/**
 * 首先有一个坑我又踩了：fastio和读入字符串不要同时使用
 * 涉及到字符串的题还是老老实实cin来的好
 *
 * 这道题其实就是并查集模板题 + 字符串哈希
 * 我们如何用字符串哈希呢？我们并不需要保证得到一个独特的数字
 * 我们可以给每一个字符串编号（cnt），读入一个新字符串，如果我们查找这个字符串的编号找不到
 * 那么我们就给这个新字符串一个编号即可
 *
 * 有了编号，我们就可以用编号来做并查集，这道题就过了
 *
 * 但是我看题解，可以直接用map<string, string>来当并查集
 * 其实原理就是直接吧father[i]改为map
 * 我们可以假定每个名字一开始的时候它的map映射就是自己
 * 然后就可以操作了
 * 看到这个的时候我人惊呆了，好棒的STL应用
 */
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

// #define DEBUG

#define MAXN 50001
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

int fa[MAXN];
void set_init()
{
    req(i,1,MAXN - 1) fa[i] = i;
}

int set_find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = set_find(fa[x]);
}

void set_union(int x, int y)
{
    if(set_find(x) != set_find(y))
    {
        fa[y] = fa[set_find(x)];
    }
}

char ch;
string str;
map<string, int> mp;
map<int, string> mpr;
int cnt, current;

void solve()
{
    set_init();
    while(1)
    {
        cin >> ch;
        if(ch == '\n') ch = getchar();
        if(ch == '$') break;
        cin >> str;

        if(mp.find(str) == mp.end())
        {
            mp[str] = ++cnt;
            mpr[cnt] = str;
        }

        if(ch == '#') current = mp[str];
        else if(ch == '+') set_union(current, mp[str]);
        else if(ch == '?') cout << str << ' ' << mpr[set_find(mp[str])] << endl;;

    }
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}