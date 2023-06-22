/**
 * @author OZLIINEX
 * @brief P1009 [NOIP1998 普及组] 阶乘之和
 * @date 2022-12-15
 */

/**
 * 试试看新写的高精度乘法
 */

#include <header.hpp>
#define MAXN 2001

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

    Number(const Number &obj)
    {
        num = new int[MAXN];
        len = obj.len;
        memcpy(num, obj.num, sizeof(int) * len);
    }

    void clear()
    {
        delete []num;
        num = new int[MAXN];
        len = 0;
    }

    // Int转为Number
    void transform(int n)
    {
        this->clear();
        while(n) num[len++] = n % 10, n /= 10;
    }

    void transform(int *n, int len)
    {
        this->clear();
        memcpy(num, n, sizeof(int) * len);
        this->len = len;
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
        this->clear();
        num[0] = 1, len = 1;
        for(int i = 2; i <= n; i++) this->cal_mul(i);
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

void solve()
{
    int n = read();
    Number temp = 1, ans = 1;
    req(i, 2, n)
    {
        temp.factorial(i); // 把temp更新为阶乘答案
        ans += temp;
    }

    ans.println();
    return;
}