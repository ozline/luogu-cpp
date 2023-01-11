/**
 * @author OZLIINEX
 * @brief P1241 括号序列
 * @date 2023-01-08
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
#include <unordered_map>

// #define DEBUG

#define MAXN 500001
#define INF 0x3f3f3f3f
#define INFLL 1LL<<60
#define writespace(a) write(a),putchar(' ')
#define writeln(a) write(a),putchar('\n')
#define req(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define fastio() std::ios::sync_with_stdio(false), std::cin.tie(0)

#ifdef DEBUG
    #define debug(...) fprintf(stdout,__VA_ARGS__)
    #define debugvar(a) cout<<"[DEBUG] "#a" = "<<a<<endl
#else
    #define debug(...) fun()
    #define debugvar(a) fun()
    void fun() { return; }
#endif

typedef long long ll;
using namespace std;


inline int read() {
    int x = 0, w = 1; char ch = 0;
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return (x*w);
}

inline void write(int x) {
    if(x == 0) { putchar('0'); return; }
    if(x<0) putchar('-'), x = -x;
    static int sta[35]; int top = 0;
    while(x) { sta[top++] = x % 10, x /= 10;}
    while (top) putchar(sta[--top] + 48);
}
/* END OF TEMPLATE */

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

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}