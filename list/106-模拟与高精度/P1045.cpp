/**
 * @author OZLIINEX
 * @brief P1045 [NOIP2003 普及组] 麦森数
 * @date 2022-12-15
 */

/**
 * 高精度快速幂 + 数学
 *
 * 首先是位数，位数我们可以知道log10(n) + 1可以获得n的位数
 * 那么我们只需要进行一些简单的数学代换就可以知道2^p的位数是
 * log10(2^p) + 1 = log10(2) * p + 1
 *
 * 位数出来了接下来就是末500位怎么求
 * 我一开始直接套了快速幂，但是发现跑31万的幂都不行
 * 后面看了题解，草了，可以只计算末500位的值，用脑子模拟了一下乘法，的确是这样
 * 越高位影响的位数的下标也越来越高，因此我们只需要强制限制位数为500位以内
 *
 * 题目又说需要前导0，因此我们直接强制限制位数为500
 *
 * 嗯。。就做出来了
 */
#include "header.hpp"
#define MAXN 6100010

// 高精度数字类
class Number
{
public:
    Number()
    {
        num = new int[MAXN];
        len = 0;
    };

    Number(int a)
    {
        num = new int[MAXN];
        len = 0;
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

    // 输出数字
    void print()
    {
        int cnt = 0;
        for(int i = len - 1; i >= 0; i--)
        {
            cnt++;
            putchar(num[i] + 48);
            if(cnt % 50 == 0) putchar('\n');
        }
    }

    void println()
    {
        this->print();
        putchar('\n');
    }

    // 翻转数组
    void reverse()
    {
        for(int i = 0; i < (len >> 1); i++) swap(num[i], num[len - i - 1]);
    }

    // 重新定义长度
    void resize(int a)
    {
        this->len = a;
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

    /**
     * @brief 高精度快速幂
     *
     * @param a 底数
     * @param b 指数
     */
    void quick_power(int a, int b)
    {
        *this = 1;
        Number base = a;
        while(b)
        {
            if(b & 1) *this *= base;
            base *= base;
            b >>= 1;
        }
    }

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

    memset(c, 0, sizeof(int) * lenc);

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

    // if(this->len > 500) this->resize(500);
    this->len = 500;
}

int p;
Number a;

void solve()
{
    p = read();
    printf("%lld\n", (ll)(log10(2) * p + 1));
    a.quick_power(2,p);
    a.num[0]--;
    a.println();
    return;
}