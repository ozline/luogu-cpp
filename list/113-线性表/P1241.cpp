/**
 * @author OZLIINEX
 * @brief P1241 括号序列
 * @date 2023-01-08
 */

#include "header.hpp"
#define MAXN 500001

stack<int> st;
string str;
int ans[MAXN];

void solve()
{
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        // debugvar(ch);
        if(str[i] == ']' && !st.empty())
        {
            int x = st.top();
            if(str[x] == '[') ans[i] = ans[x] = 1, st.pop();
            continue;
        }

        if(str[i] == ')' && !st.empty())
        {
            int x = st.top();
            if(str[x] == '(') ans[i] = ans[x] = 1, st.pop();
            continue;
        }

        st.push(i);
    }

    for(int i = 0; i < str.length(); i++)
    {
        if(ans[i]) cout << str[i];
        else
        {
            if(str[i] == '(' || str[i] == ')') cout << "()";
            else cout << "[]";
        }
    }
    return;
}