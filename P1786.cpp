/**
 * @file P1786.cpp
 * @author ozlinex
 * @brief P1786 帮贡排序
 * @date 2023-07-14
 */

#include "header.hpp"
#define MAXN 500001

int transPosition(string a)
{
    if(a == "BangZhu") return 0;
    if(a == "FuBangZhu") return 1;
    if(a == "HuFa") return 2;
    if(a == "ZhangLao") return 3;
    if(a == "TangZhu") return 4;
    if(a == "JingYing") return 5;
    if(a == "BangZhong") return 6;
}

struct Node
{
    int position, value, level;
    string name;

    Node():position(0),value(0),level(0),name(""){};
    Node(string a, int b, int c, int d):name(a),position(b),value(c),level(d){};
};

int n;
Node node[MAXN], cnt;
int position[MAXN], value[MAXN], level[MAXN]; // 职位、帮贡、等级
string name[MAXN]; // 姓名

void solve()
{
    string tmpPosition;
    cin >> n;
    req(i, 1, n)
    {
        cin >> name[i] >> tmpPosition >> value[i] >> level[i];
    }
}