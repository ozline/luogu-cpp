/**
 * @author OZLIINEX
 * @brief P1093 奖学金
 * @date 2022-12-15
 */

#include "header.hpp"
#define MAXN 301

struct Mark
{
    int a, b, c;
    int idx;
    Mark(int a, int b, int c):a(a),b(b),c(c){};
    Mark():a(0),b(0),c(0){};

    bool operator<(const Mark &obj) const
    {
        if((a + b + c) != (obj.a + obj.b + obj.c))
        {
            return (a + b + c) > (obj.a + obj.b + obj.c);
        }
        else if(a != obj.a) return a > obj.a;
        // else if(b != obj.b) return b > obj.b;
        // else if(c != obj.c) return c > obj.c;
        else return idx < obj.idx;

    }
};

int n;
Mark a[MAXN];

void solve()
{
    n = read();
    req(i, 1, n)
    {
        a[i].a = read(), a[i].b = read(), a[i].c = read(), a[i].idx = i;
    }
    sort(a + 1, a + 1 + n);
    req(i, 1, 5)
    {
        printf("%d %d\n",a[i].idx, a[i].a + a[i].b + a[i].c);
    }
    return;
}