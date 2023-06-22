/**
 * @author OZLIINEX
 * @brief P3871 TJOI2010 中位数
 * @date 2022-07-25
 */

#include "header.hpp"
#define MAXN 500001

void start()
{

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
            num = read();
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
}