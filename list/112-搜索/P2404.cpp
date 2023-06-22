/**
 * @author OZLIINEX
 * @brief P2404 自然数的拆分问题
 * @date 2023-03-26
 */

#include "header.hpp"
#define MAXN 500001

int n;

vector<int> v;
vector<int>::iterator it;

void print()
{
    if(v.size() < 2) return;

    for(it = v.begin(); it != v.end(); it++)
    {
        if(it != v.begin()) putchar('+');

        putchar(*it + 48);
    }
    putchar('\n');
}

void search(int last)
{
    if(last == 0)
    {
        print();
        return;
    }

    req(i, 1, last)
    {
        if(!v.empty() && i < v.back()) continue;
        v.push_back(i);
        search(last - i);
        v.pop_back();
    }
}


void solve()
{
    cin >> n;
    search(n);
}