/**
 * @author OZLIINEX
 * @brief P1229 遍历问题
 * @date 2023-01-21
 */

/**
 * 前序遍历：根左右
 * 中序遍历：左根右
 * 后序遍历：左右根
 *
 * 现在给你一个前序遍历和一个后序遍历，求可能的中序遍历的树木
 * 我们可以注意到，前序遍历的第一个一定是根，后序遍历的第一个也肯定是根
 *
 * 同时，只有一个儿子的节点才会在知道前序和后序的情况下有多种中序
 * 这时候题目就转化成找只有一个子节点的点的数目
 * 答案是2^i，其中i是这种节点的数目，因为可以放左边也可以放右边嘛
 *
 * 我们可以有一个规律，就是，如果先序遍历中的某个元素A的后继是B，如果在后序遍历中B的前驱元素是A，那么A就只有一个结点
 *
 * 先序遍历中，如果A只有一个子树B，那么在先序遍历中A一定在B前，在后序遍历中B一定在A前
 *
 * 回顾一下，先序遍历：根左右 后序遍历：左右根，如果假设没有右子树，那么先序就是根左，后序就是左根，是吧！
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

string str1, str2;
int ans;

void solve()
{
    cin >> str1 >> str2;
    int len1 = str1.length();
    int len2 = str1.length();
    req(i, 0, len1 - 1)
    {
        req(j, 1, len2 - 1)
        {
            if(str1[i] == str2[j] && str1[i + 1] == str2[j - 1]) ans++;
        }
    }
    printf("%lld\n", ll(1 << ans));
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