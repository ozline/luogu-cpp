/**
 * @author OZLIINEX
 * @brief P2392
 * @date 2023-03-18
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

#define MAXN 61
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


int s[5];
int a[65];


// 数据量太小，可以直接dfs
int ans = INF;
void dfs(int len, int now, int left, int right) {
    if(len < now)
    {
        ans = min(ans, max(left, right));
        return;
    }
    dfs(len, now + 1, left + a[now], right);
    dfs(len, now + 1, left, right + a[now]);
}

// 当然，我们也可以使用dp
int sum = 0;
int f[100001];
int work(int n)
{
    req(i, 1, 100001) f[i] = 0;

    req(i, 1, s[n])
    {
        for(int j = sum; j >= 0; j--)
        {
            if(f[j]) f[j + a[i]] = 1;
        }
    }

    int tmp = sum, res;
    req(i, 0, sum)
    {
        if(f[i] && tmp >= abs(i - (sum - i)))
        {
            tmp = abs(i - (sum - i));
            res = max(i, sum - i);
        }
    }

    return res;
}

void solve()
{
    int temp = 0;
    req(i ,1, 4) cin >> s[i];
    req(j, 1, 4)
    {
        ans = INF, sum = 0;

        req(i, 1, s[j]) cin >> a[i], sum+=a[i];
        // dfs(s[j], 1, 0, 0);
        ans = work(j);
        // debugvar(ans);

        temp += ans;
    }

    printf("%d\n", temp);

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