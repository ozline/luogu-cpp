/**
 * @author OZLIINEX
 * @brief P3958 NOIP2017 奶酪
 * @date 2022-07-28
 */

/* 以现在看过去，以前的我好摆啊 */

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

struct Node
{
    ll x;
    ll y;
    ll z;
};

int n,h,r; //空洞数量、奶酪高度和空洞半径
Node node[10001];

/* 并查集 */
int father[MAXN];
int ranks[MAXN];

void set_init()
{
    for(int i=0;i<=MAXN;i++)
    {
        father[i] = i;
        ranks[i] = 0;
    }
}
ll set_find(int x)
{
    if( father[x] != x)
    {
        father[x] = set_find(father[x]);
    }

    return father[x];
}
void set_link(ll x,ll y)
{
    if(ranks[x] > ranks[y]) father[x] = y;
    else
    {
        father[x] = y;
        if(ranks[x] == ranks[y]) ranks[y] ++;
    }
}

void set_union(ll x, ll y)
{
    ll fx = set_find(x);
    ll fy = set_find(y);

    if(fx != fy) set_link(fx,fy);
}
/* 并查集 */

double cal_distance(Node x,Node y)
{
    ll x1 = x.x - y.x;
    ll y1 = x.y - y.y;
    ll z1 = x.z - y.z;
    return sqrt(x1*x1 + y1*y1 + z1*z1);
}

void solve()
{
    read(n),read(h),read(r);

    set_init();

    int list_bottom[3001],list_top[3001]; //储存连接表面的点
    int count_bottom = 0, count_top = 0; //计数
    for(int i=1;i<=n;i++){
        read(node[i].x);
        read(node[i].y);
        read(node[i].z);

        if(node[i].z - r <= 0) list_bottom[count_bottom ++] = i;
        if(node[i].z + r >= h) list_top[count_top ++ ] = i;
    }

    bool vis[2001][2001] = { false };

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(vis[i][j]) continue;                     //已经连通过了
            if(i == j) continue;                        //同点跳过
            if(set_find(i) == set_find(j)) continue;    //同父跳过
            double distance = cal_distance(node[i],node[j]); //计算两点之间距离
            if(distance <= (r + r) )//表明这两个点已经连通了
            {
                set_union(i,j); //连通这两个点
                vis[i][j] = vis[j][i] = true; //这两个点标记为已访问，减少重复计算
            }
        }
    }

    for(int i=0;i<count_top;i++)
    {
        for(int j=0;j<count_bottom;j++)
        {
            if(set_find(list_top[i]) == set_find(list_bottom[j]))
            {
                puts("Yes");
                return;
            }
        }
    }

    puts("No");
    return;
}

int main()
{
    #ifdef DEBUG
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    clock_t start,finish;
    double totaltime;
    start = clock();
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    /*START*/

    int t;
    read(t);
    while(t--) solve();


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