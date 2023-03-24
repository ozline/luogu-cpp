/**
 * @author OZLIINEX
 * @brief P1101 填涂颜色
 * @date 2023-03-24
 */


// 再提醒一次！不要fastio()后又特么的去用scanf和printf！！！
// 又浪费了时间
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

const char list[] = "yizhong";
int get_index(char ch)
{
    for(int i = 0; i < 8; i++)
        if (list[i] == ch) return i;
    return -1; // not found
}

int n;
char a[201][201];
int b[201][201]; // 0=not visit, 1=normal

int pos_x[] = {0, 0, 1, 1, 1, -1, -1, -1};
int pos_y[] = {1, -1, 0, 1, -1, 0, 1, -1};

bool dfs(int x, int y, char ch, int px, int py)
{
    if(ch == 'g')
    {
        b[x][y] = 1;
        return true;
    }

    int idx = get_index(ch);

    if(idx == -1) return false;

    if(x + px > n || x + px < 1 || y + py > n || y + py < 1) return false;
    if(a[x + px][y + py] != list[idx + 1]) return false;

    return b[x][y] = dfs(x + px, y + py, list[idx + 1], px, py) ? 1 : b[x][y];
}

void solve()
{
    cin >> n;
    req(i, 1, n) req(j, 1, n) cin >> a[i][j];

    req(i, 1, n) req(j, 1, n)
    {
        if(a[i][j] == 'y')
        {
            req(k, 0, 7) dfs(i, j, 'y', pos_x[k], pos_y[k]);
        }
    }

    req(i, 1, n)
    {
        req(j, 1, n)
        {
            if(!b[i][j]) cout << '*';
            else cout << a[i][j];
        }
        putchar('\n');
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