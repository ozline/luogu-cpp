/**
 * @author OZLIINEX
 * @brief P1591 阶乘数码
 * @date 2022-12-15
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
using namespace std;


inline int read() {
    int x = 0, w = 1; char ch = 0;
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return (x*w);
}

inline void write(int x) {
    if(x == 0) { putchar('0'); return; }
    if(x<0) putchar('-'), x = -x;
    static int sta[35]; int top = 0;
    while(x) { sta[top++] = x % 10, x /= 10;}
    while (top) putchar(sta[--top] + 48);
}
/* END OF TEMPLATE */

// 高精度数字类
class Number
{
public:
    Number()
    {
        num = new int[MAXN], len = 0;
    };

    Number(int a)
    {
        num = new int[MAXN], len = 0;
        this->transform(a);
    };

    Number(char *a)
    {
        num = new int[MAXN], len = 0;
        this->transform(a);
    }

    Number(const Number &obj)
    {
        num = new int[MAXN];
        len = obj.len;
        memcpy(num, obj.num, sizeof(int) * len);
    }

    void clean()
    {
        delete []num;
        num = new int[MAXN];
        len = 0;
    }

    // Int转为Number
    void transform(int n)
    {
        this->clean();
        while(n) num[len++] = n % 10, n /= 10;
    }

    void transform(int *n, int len)
    {
        this->clean();
        memcpy(num, n, sizeof(int) * len);
        this->len = len;
    }

    void transform(char *a)
    {
        this->clean();
        this->len = strlen(a);
        for(int i = 0; i < len; i++) this->num[i] = a[len - i - 1] - 48;
    }

    // 打印数字
    void println()
    {
        for(int i = len - 1; i >= 0; i--) putchar(num[i] + 48);
        putchar('\n');
    }

    // 数字翻转
    void reverse()
    {
        for(int i = 0; i < (len >> 1); i++) swap(num[i], num[len - i - 1]);
    }

    Number& operator=(const Number &a)
    {
        if(this == &a) return *this;
        len = a.len;
        memcpy(num, a.num, sizeof(int) * len);
        return *this;
    }

    Number& operator=(const int &a)
    {
        this->transform(a);
        return *this;
    }

    Number& operator=(char *a)
    {
        this->transform(a);
        return *this;
    }

    Number& operator+=(Number &a)
    {
        this->cal_add(&a);
        return *this;
    }

    Number& operator+=(const int a)
    {
        this->cal_add(a);
        return *this;
    }

    Number& operator*=(Number &a)
    {
        this->cal_mul(&a);
        return *this;
    }

    Number& operator*=(const int a)
    {
        this->cal_mul(a);
        return *this;
    }

    // 高精度乘法
    void cal_mul(Number *obj);
    void cal_mul(int i)
    {
        Number temp = i;
        this->cal_mul(&temp);
    }

    // 高精度加法
    void cal_add(Number *obj);
    void cal_add(int i)
    {
        Number temp = i;
        this->cal_add(&temp);
    }

    // 高精度阶乘
    void factorial(int n)
    {
        this->clean();
        num[0] = 1, len = 1;
        for(int i = 2; i <= n; i++) this->cal_mul(i);
    }

    // 统计某个数字出现次数
    int num_count(int target)
    {
        int ans = 0;
        for(int i = 0; i < this->len; i++)
        {
            if(num[i] == target) ans++;
        }
        return ans;
    }
private:
    int *num, len; // 数字数组，长度
};

// 高精度加法
inline void Number::cal_add(Number *obj)
{
    int len = max(this->len, obj->len);
    int cf = 0, *c = new int[MAXN];
    memset(c, 0, sizeof(int) * len);
    req(i, 0, len - 1)
    {
        if(cf) c[i] += cf;
        if(i < this->len) c[i] += num[i];
        if(i < obj->len) c[i] += obj->num[i];
        cf = c[i] / 10;
        c[i] %= 10;
    }

    if(cf) c[len++] = cf;

    this->transform(c, len);

    delete []c;
}

// 高精度乘法
inline void Number::cal_mul(Number *obj)
{
    int lenc = this->len + obj->len - 1, cf = 0;
    int *c = new int[MAXN];

    memset(c, 0, sizeof(char) * lenc);

    req(i, 0, this->len - 1)
    {
        req(j, 0, obj->len - 1)
            c[i + j] += this->num[i] * obj->num[j];
    }

    // 处理进位
    req(idx, 0, lenc - 1)
    {
        if(cf) c[idx] += cf;
        cf = c[idx] / 10, c[idx] %= 10;
    }
    while(cf)
    {
        c[lenc] += cf;
        cf = c[lenc] / 10, c[lenc] %= 10;
        lenc++;
    }

    // 解决前导零，但保留零
    while(!c[lenc - 1] && lenc-- > 1);

    this->len = lenc;
    memcpy(this->num, c, sizeof(int) * lenc);

    delete []c;
    obj->reverse();
}

int n, target, temp;
char str[MAXN];
Number num;

void solve()
{
    cin >> n;
    while(n--)
    {
        cin >> temp >> target;
        num.factorial(temp);
        printf("%d\n",num.num_count(target));
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