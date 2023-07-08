/**
 * @file P2089.cpp
 * @author ozlinex
 * @brief P2089 烤鸡
 * @date 2023-06-23
 */

// 题意：有一家烤鸡店，每只鸡都有一个编号，编号为1~10，每只鸡都有一个重量，重量为1~3kg，现在要从中选出10只鸡，使得这10只鸡的编号之和为n，重量之和为m，问有多少种选法？

// 简单递归解决

#include "header.hpp"
#define MAXN 500001

vector<string> l;

void loop(int last, int idx, string s)
{
    if(idx == 10 && (last > 3 || last < 1) || idx > 10) return;
    if(idx < 10 && last < 2) return; // 没到最后一个编号也无力回天

    if(idx == 10) { l.push_back(s + " " + to_string(last)); return; }

    if(idx != 1) s += " ";

    req(i, 1, min(last, 3)) loop(last - i, idx + 1, s + to_string(i));
}

void solve()
{
    loop(read(), 1, "");
    if(l.size() == 0) { puts("0"); return; }
    cout << l.size() << endl;
    req(i, 0, l.size() - 1) cout << l[i] << endl;
}