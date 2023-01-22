/**
 * @author OZLIINEX
 * @brief NowCoder - Tokisukaze and K-Sequence
 * @date 2023-01-22
 */

/**
 * 其实很明显可以看到，假设k = 4，也就是划分4段
 * 那么如果某一个数x出现了4次，那么这个数就可以划分到4段中的任意一段
 * 也就是说这个数对答案的贡献就是它本身
 * 那么这时候如果某个数x出现了5次呢？我们可以注意到必然有一段这个数字
 * 出现了2次，那么在这一段里这个数字不能做出贡献，所以答案是3
 * 如果这个x出现了6次呢？我们可以求的最大期望是某个段里这个数字出现了
 * 3次！所以答案还是3。
 * 也就是说，对于给定的k，我们的某一个数字对在这个k下的期望答案贡献就
 * 是(cnt[x] > k)? (k - 1) : cnt[x]
 *
 * 很明显，这样的操作最坏情况O(n^2)的，10^10可能过不去
 * 我们可以考虑记录cnt[x]的增长轨迹
 * 比如例子中的2 2 1，我们cnt[2]会0->1再1->2
 * 那么我们就取一个temp数组，记录这个cnt[x]的变化情况
 * 也就是代码中的temp[ cnt[x] ]++
 *
 * temp[i]表示的就是出现次数>=i次的数字的个数
 * temp[1]还有另一个含义：这个序列中出现了几种数字
 *
 * 对于每个k，我们可以注意到所有出现次数>k的数字都不能作为贡献，于是
 * 我们就有了temp[1] - temp[k + 1]
 * 因为出现次数为(k + 2)的数字一定会在temp[k + 1]中被记录一次
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

#define DEBUG

#define MAXN 100001
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

int t, n;
int a[MAXN], cnt[MAXN], temp[MAXN];
int ans, len;

void solve()
{
    t = read();
    while(t--)
    {
        memset(a, 0, sizeof(a));
        memset(cnt, 0, sizeof(cnt));
        memset(temp, 0, sizeof(temp));
        n = read(), ans = 0;

        req(i, 1, n)
        {
            a[i] = read();
            cnt[ a[i] ]++; // 统计这个数字出现的次数
            temp[ cnt[ a[i] ] ]++; // 统计出现次数的出现次数
        }

        // 第一版，这里没有用到temp
        // sort(a + 1, a + 1 + n);
        // len = unique(a + 1, a + 1 + n) - a - 1;

        // req(i, 1, n)
        // {
        //     ans = 0;
        //     req(j, 1, len)
        //     {
        //         if(cnt[ a[j] ] > i) ans += i - 1;
        //         else ans += cnt[ a[j] ];
        //     }
        //     printf("%d\n", ans);
        // }

        // /*
        //     可能会T，最坏期望是这个1 - 10^5的数字各个不一样
        //     那么for套for就是10^10数量级，就过不去了

        //     也就是说，需要优化一下
        // */

        req(i, 1, n)
        {
            ans += temp[i];
            printf("%d\n", ans - temp[i + 1]);
        }
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