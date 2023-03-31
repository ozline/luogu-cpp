/**
 * @author OZLIINEX
 * @brief P1080 [NOIP2012 提高组] 国王游戏
 * @date 2023-03-31
 */

// 夸一下自己，早上2点多在床上的时候看了一下题目就猜到贪心 a * b了
// 还是有一定的算法基础嘛！
// 试着写一下高精加减乘除吧

// 嗯，写了还是蛮久的，尤其是这个高精度除法
// 这个程序写了这几个函数: movep(), iflowerp(), multip(), divp(), reverse(), spiltnum()
// 分别表示：高精度数字赋值、高精度数字大小判断、高精度乘法、高精度除法、高精度数字数组反转，普通数字转高精度数字

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

#define MAXN 20001
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
struct Node {
    int a, b;

    Node():a(0),b(0){};
    Node(int a, int b):a(a),b(b){};

    bool operator<(const Node &obj) const {
        return (a * b) < (obj.a * obj.b);
    }
};


int n;
Node a[MAXN];
int perfix[MAXN], cnt; // 国王左手的数字

// reverse array
void reverse(int *arr,int len)
{
    req(i, 1, len >> 1) swap(arr[i], arr[len + 1 - i]);
}

// print array
void print(int *arr, int len)
{
    if(len <= 0) { puts("0"); return; }
    for(int i = len; i > 0; i--) printf("%d", arr[i]);
    putchar('\n');
}

// spilt num to arr, return lens, store by reverse
int spiltnum(int x, int *arr)
{
    if(x == 0) return 1;
    if(x < 0 ) x = -x;

    int ans = 0;
    while(x) { arr[++ans] = x % 10, x /= 10; }
    return ans;
}


int temp[MAXN], templen;    // 计算过程中临时数组
int num[MAXN], numlen;      // 计算过程中临时数组

// judge arr a and arr b, return (a < b), especially return -1 if a == b;
int iflowerp(int *a, int cnta, int *b, int cntb)
{
    if(cnta != cntb) return (cnta < cntb); // 判断位数
    for(int i = cnta; i > 0; i--)
    {
        if(a[i] == b[i]) continue;
        return a[i] < b[i];
    }
    return -1;
}

// merge a -> b
void movep(int *a, int *cnta, int *b, int *cntb)
{
    req(i, 1, *cnta) b[i] = a[i];
    *cntb = *cnta;
}

// 对perfix进行高精乘法
void multip(int x)
{
    // 初始化
    memset(temp, 0, sizeof(temp)); int cf = 0; // 进位符号
    numlen = spiltnum(x, num), templen = numlen + cnt;
    // 模拟乘法过程
    req(i, 1, numlen) req(j, 1, cnt) temp[i + j - 1] += num[i] * perfix[j];
    req(i, 1, templen)
    {
        if(cf) temp[i] += cf;
        cf = temp[i] / 10, temp[i] %= 10;
    }
    // 处理额外进位
    while(cf)
    {
        temp[++templen] += cf;
        cf = temp[templen] / 10; temp[templen] %= 10;
    }
    while(!temp[templen] && templen-- > 1); // 处理前导零
    movep(temp, &templen, perfix, &cnt);    // 赋值
}

// 高精除法(高精除单精,向下取整,答案留在ans中)
void divp(int x, int *ans, int *anscnt)
{
    memset(temp, 0, sizeof(temp));
    int numlen = spiltnum(x, num), d = 0;  // 被除数长度 余数
    if(numlen > cnt) { temp[1] = 0, templen = 1; return; }

    templen = cnt;
    for(int i = cnt; i > 0; i--)
    {
        temp[i] = (d * 10 + perfix[i]) / x;
        d = (d * 10 + perfix[i]) % x;
    }

    while(!temp[templen] && templen-- > 1); // 处理前导零
    movep(temp, &templen, ans, anscnt);     // 赋值
}


int ans[MAXN], anslen; // 答案

void solve()
{
    char ch; int tmp, res[MAXN], rescnt;
    scanf("%d", &n);

    // 读到换行结束
    while(ch = getchar(), ch != '\n');

    // 读入国王左手的数字 国王右手的数字似乎没什么用
    while(ch = getchar(), isdigit(ch)) perfix[++cnt] = ch - 48;
    reverse(perfix, cnt);

    // 读掉国王右手的数字
    while(ch = getchar(), ch != '\n');

    req(i, 1, n) a[i].a = read(), a[i].b = read();
    sort(a + 1, a + 1 + n);

    req(i, 1, n)
    {
        divp(a[i].b, res, &rescnt);
        if(iflowerp(ans, anslen, res, rescnt)) movep(res, &rescnt, ans, &anslen);
        multip(a[i].a);
    }

    print(ans, anslen);

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