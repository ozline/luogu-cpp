/**
 * @author OZLIINEX
 * @brief P3372 线段树 模板
 * @date 2022-07-22
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


#define MAXN 100010
#define INF 0x3f3f3f3f
#define debug(...) fprintf(stdout,__VA_ARGS__)

typedef long long ll;
using namespace std;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

inline void write(ll x) {
    static int sta[35];
    int top = 0;
    do sta[top++] = x % 10, x /= 10;
    while (x);
    while (top) putchar(sta[--top] + 48);
}

inline void writeln(ll x)
{
    write(x);
    putchar('\n');
}
/* END OF TEMPLATE */

struct Node
{
    int left; //左儿子
    int right; //右儿子
    ll sum; //线段和
    ll add; //懒标记
};

Node tree[MAXN*4+2];
int a[MAXN]; // zzz..

//编号为p的区间，左儿子为2p，右儿子为2p+1
void build(int p,int l,int r)
{
    //编号为p的节点维护区间为l到r
    tree[p].left = l;
    tree[p].right = r;
    if(l == r)
    {
        //相等，说明这是个叶子结点，直接让维护的值等于a[i]
        tree[p].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    //维护的值等于左儿子加上右儿子
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p].sum = tree[p*2].sum + tree[p*2+1].sum;
    return;
}

void push_down(int p)
{
    if(tree[p].add)//如果Lazy标记不为零，则下传，修改左右儿子维护的值
    {
        tree[p*2].sum += tree[p].add*(tree[p*2].right - tree[p*2].left + 1);
        tree[p*2+1].sum += tree[p].add*(tree[p*2+1].right - tree[p*2+1].left + 1);

        tree[p*2].add += tree[p].add;
        tree[p*2+1].add += tree[p].add;

        tree[p].add = 0; //下传之后把自己的lazy标记为0
    }
}

void update_add(int p,int x,int y,int z)
{
    if(x <= tree[p].left && y >= tree[p].right)//若被覆盖，就对其进行修改
    {
        tree[p].sum += (ll)z*(tree[p].right - tree[p].left + 1);
        tree[p].add += z;
        return;
    }

    push_down(p); //若没有覆盖，则继续向下查找，考虑到儿子维护的区间可能存在懒标记而没有修改，因此下放这个懒标记
    int mid = (tree[p].left + tree[p].right) >> 1;
    if(x <= mid) update_add(p*2,x,y,z);
    if(y > mid) update_add(p*2+1,x,y,z);
    tree[p].sum = tree[p*2].sum + tree[p*2+1].sum; //最终维护的值等于左儿子的值加上右儿子的值
}

ll query(int p,int x,int y)
{
    if(x <= tree[p].left && y >= tree[p].right) return tree[p].sum; //如果被覆盖，则返回维护的值

    push_down(p); //下传懒标记，并查询左右儿子

    int mid = (tree[p].left + tree[p].right) >> 1;
    ll ans = 0;
    if(x <= mid) ans += query(p*2,x,y);
    if(y > mid) ans += query(p*2+1,x,y); //累加答案，返回左右儿子

    return ans ;
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

    /*START*/

    int n = read(), m = read();
    for(int i=1;i<=n;i++) a[i] = read();

    build(1,1,n);

    for(int i=1;i<=m;i++)
    {
        int q = read();
        int x = read(), y = read();
        if(q == 1)
        {
            int z = read();
            update_add(1,x,y,z);
        }
        else
        {
            writeln(query(1,x,y));
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