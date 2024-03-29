/**
 * @author OZLIINEX
 * @brief 高精度数字类
 * @date 2022-12-15
 */

#include <iostream>

#define MAXN 2001
#define req(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)

typedef long long ll;
using namespace std;

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
        for(int i = len - 1; i >= 0; i--) putchar(num[i] + 48);
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
}