/**
 * @author OZLIINEX
 * @brief P1305 新二叉树
 * @date 2023-01-21
 */

/**
 * 再来一遍..前序遍历 = 根左右
 *
 * 这道题对于理解前中后遍历有很大帮助
 * 比如原来是abc，现在对b扩展有bdi，也就是b的左儿子和右儿子是d和i
 * 那么我们为什么可以直接在b的后面插入di？
 * 考虑如下这个前序遍历：abdic
 * 而前序遍历在二叉树中的体现就是先把左边挖到底，到不能挖了再回退一格尝试挖右边
 * 以此类推可以发现，前序遍历就是直接在b后面插入di即可
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

int n;
string str, temp;

void solve()
{
    cin >> n;
    cin >> str;
    req(i, 2, n)
    {
        cin >> temp;
        int x = str.find(temp[0]);
        str.erase(x, 1);
        str.insert(x, temp);
    }
    req(i, 0, str.size() - 1)
    {
        if(str[i] == '*') continue;
        cout << str[i];
    }
    return;
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    fastio(); solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}