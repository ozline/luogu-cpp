/**
 * @author OZLIINEX
 * @brief 码上掘金 - 寻友之旅
 * @date 2023-02-14
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

#define DEBUG

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
typedef unsigned long long ull;
using namespace std;


inline int read() {
    int x = 0, w = 1; char ch = 0;
    while(ch < '0' || ch > '9') { if(ch == '-') w = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return(x * w);
}

inline void write(int x) {
    if(x == 0) { putchar('0'); return; }
    static int sta[35]; int top = 0;
    if(x<0) putchar('-'), x = -x;
    while(x) { sta[top++] = x % 10, x /= 10; }
    while(top) putchar(sta[--top] + 48);
}
/* END OF TEMPLATE */

struct Node
{
  int cnt;  // 当前步数
  int x;    // 当前位置

  Node(int cnt, int x):cnt(cnt),x(x){};
};

queue<Node> q;
int n, k;
int ans = INF;

void bfs()
{
  while(!q.empty())
  {
    Node now = q.front();
    q.pop();

    while(now.cnt >= ans && q.size())
    {
        now = q.front();
        q.pop();
    }

    // 计算答案
    if(now.x >= k)
    {
      ans = min(ans, now.cnt + now.x - k);
      continue;
    }

    q.push(Node(now.cnt + 1, now.x - 1));
    q.push(Node(now.cnt + 1, now.x + 1));
    if(now.x * 2 <= k) q.push(Node(now.cnt + 1, now.x * 2));
  }
}

void solve()
{
    cout<< ans << endl;
  n = read(), k =read();
  q.push(Node(0, n));
  bfs();
  printf("%d\n", ans);
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