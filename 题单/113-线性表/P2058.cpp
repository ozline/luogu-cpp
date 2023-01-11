/**
 * @author OZLIINEX
 * @brief [NOIP2016 普及组] 海港
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

#define MAXN 100001
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

struct Node
{
    int t, k;
    vector<int> v;
};

int n, t, k;
queue<Node> Q;
int cnt[MAXN], ans;
vector<int>::iterator it;

void solve()
{
    n = read();
    req(i, 1, n)
    {
        Node temp;
        temp.t = read(), temp.k = read();
        while(!Q.empty())
        {
            Node node = Q.front();
            if(node.t + 86400 <= temp.t)
            {
                Q.pop();
                for(it = node.v.begin(); it != node.v.end(); it++)
                {
                    cnt[*it]--;
                    if(cnt[*it] == 0) ans--;
                }
            }
            else break;
        }

        req(j, 1, temp.k)
        {
            int x = read();
            temp.v.push_back(x);
            if(cnt[x] == 0) ans++;
            cnt[x]++;
        }
        Q.push(temp);
        writeln(ans);
    }
    return;
}

int main()
{
    #ifdef DEBUG
        freopen("in.in","r",stdin); freopen("out.out","w",stdout);
    #endif

    fastio(); solve();

    #ifdef DEBUG
        fclose(stdin); fclose(stdout);
    #endif
    return 0;
}