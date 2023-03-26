/**
 * @author OZLIINEX
 * @brief P3871 TJOI2010 中位数
 * @date 2022-07-25
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

// #define DEBUG
#define MAXN 500001
#define INF 0x3f3f3f3f
#define INFLL ( 1LL<<60 )
#define debug(...) fprintf(stdout,__VA_ARGS__)

typedef long long ll;
using namespace std;


template<typename T>
T read(T &x) {
    x = 0;
    T w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    x *= w;
    return x;
}

template<typename T>
inline void write(T x) {
    if( x < 0)
    {
        putchar('-');
        x = -x;
    }
    static int sta[35];
    int top = 0;
    do sta[top++] = x % 10, x /= 10;
    while (x);
    while (top) putchar(sta[--top] + 48);
}

template<typename T>
inline void writeln(T x)
{
    write(x);
    putchar('\n');
}

template<typename T>
inline void writespace(T x)
{
    write(x);
    putchar(' ');
}
/* END OF TEMPLATE */

int main()
{
    #ifdef DEBUG
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    clock_t start,finish;
    double totaltime;
    start = clock();
    #endif

    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);

    /*START*/

    int n,m,num;
    // read(n);
    cin>>n;

    priority_queue<int> Q1;
    priority_queue<int, vector<int>, greater<int> > Q2;


    for(int i=1;i<=n;i++)
    {
        // read(num);
        cin>>num;

        if(i  == 1)
        {
            Q1.push(num);
            continue;
        }

        if(num > Q1.top()) Q2.push(num);
        else Q1.push(num);

        while(Q2.size() > Q1.size() + 1)
        {
            Q1.push(Q2.top());
            Q2.pop();
        }

        while(Q1.size() > Q2.size())
        {
            Q2.push(Q1.top());
            Q1.pop();
        }
    }

    // read(m);
    cin>>m;

    string s;
    while(m--)
    {
        cin>>s;
        if( s[0] == 'a' )
        {
            read(num);
            if(num > Q1.top()) Q2.push(num);
            else Q1.push(num);

            while(Q2.size() > Q1.size() + 1)
            {
                Q1.push(Q2.top());
                Q2.pop();
            }

            while(Q1.size() > Q2.size())
            {
                Q2.push(Q1.top());
                Q1.pop();
            }
        }
        else if( s[0] == 'm' )
        {
            writeln( (Q1.size() == Q2.size()) ? min(Q1.top(),Q2.top()) : Q2.top());
        }
    }



    /*END*/

    #ifdef DEBUG
    finish = clock();
    totaltime = (double)(finish-start)/CLOCKS_PER_SEC*1000;
    printf("\n耗时: %.6lf ms\n",totaltime);
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}