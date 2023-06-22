/**
 * @author OZLIINEX
 * @brief P1629
 * @date 2022-10-11
 */
#include "header.hpp"
#define MAXN 101

struct Ballot
{
    int idx;
    string num;

    Ballot():idx(0),num(""){};

    bool operator<(const Ballot &b) const
    {
        if(num.length() == b.num.length()) return num > b.num;
        else return num.length() > b.num.length();
    }
};

int n;
Ballot a[MAXN];

void solve()
{
    cin>> n;
    req(i, 1, n)
    {
        a[i].idx = i;
        cin >> a[i].num;
    }

    sort(a + 1, a + 1 + n);

    printf("%d\n%s", a[1].idx, a[1].num.c_str());
    return;
}