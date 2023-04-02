/**
 * @author OZLIINEX
 * @brief P8778 [蓝桥杯 2022 省 A] 数的拆分
 * @date 2023-04-02
 */

// 我感觉难度蛮大的，但是不知道为什么洛谷只有黄题

// 如果一个数可以拆分成题目中的那样，也就是 a = x1^y1 * x2^y2
// 那么一定有 a = x^k(k > 2) 或 a = x^2 * y^3

// 先考虑第二种情况，我们可以知道这个数据范围差不多是5次方
// 我们考虑10^18开5次根，答案差不多是4000左右（可以估到比10^4来的小）
// 那么4000以内的素数我们就暴力判断，对于大于4000的数，要适配a，只可能是2、3、4次方
// 其中4次方包含在了2次方内，我们只需要判断2或者3次方就可以了

// 有个tips，k1 * y1 + k2 * y2
// 这组表达式中，只要y1 = 2, y2 = 3，那么这个表达式可以表示出所有大于1的整数
// 是道数论题了，我不会

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

// 线性筛素数
bool not_prime[4010];
int prime[4010], cnt;
void init_prime(int n)
{
    req(i, 2, n)
    {
        if(!not_prime[i])
        {
            prime[++cnt] = i;
            for(int j = i + i; j <= n; j += i) not_prime[j] = true;
        }
    }
}

bool check(ll x)
{
    // 检查平方
    ll y = pow(x, 0.5);
    if(y * y == x || (y + 1) * (y + 1) == x) return true;

    // 检查立方
    y = pow(x, 1.0 / 3);
    if(y * y * y == x || (y + 1) * (y + 1) * (y + 1) == x) return true;

    return false;
}


int t;
ll num;

bool checkans;

void solve()
{
    init_prime(4000);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &num);
        if(check(num)) { puts("yes"); continue; }

        bool flag = true;
        req(i, 1, cnt)
        {
            if(num % prime[i] == 0)
            {
                int now = 0;
                while(num % prime[i] == 0) now++, num /= prime[i];
                if(now == 1){ flag = false; break; }
            }
        }

        puts((flag && check(num)) ? "yes" : "no");
    }
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    // fastio();
    solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}