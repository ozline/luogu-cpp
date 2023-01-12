/**
 * @author OZLIINEX
 * @brief 【深基16.例7】普通二叉树（简化版）
 * @date 2023-01-11
 */

// 实现一个BST，Binary Search Tree，二叉搜索树

// 但是最坏情况是会退化成一条链，这时候搜索复杂度就会达到最大，为了避免这个情况，我们会有了平衡树这一概念

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

#define INTMAX 2147483647

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


static int nums;

struct Node
{
    Node *left, *right;
    int val, cnt, size; // 值 计数 大小

    Node(int x):val(x),cnt(1),size(1){};

    void insert(int x) // 插入
    {
        this->size++;
        if(this->val == x) { this->cnt++; return; }

        if (x < this->val)
        {
            if (this->left == NULL) this->left = new Node(x), nums++;
            else this->left->insert(x);
        }
        else
        {
            if (this->right == NULL) this->right = new Node(x), nums++;
            else this->right->insert(x);
        }
    }

    // 找前驱
    int query_front(int val, int ans)
    {
        if(this->val >= val)
        {
            if(this->left == NULL) return ans;
            else return this->left->query_front(val, ans);
        }
        else
        {
            if(this->right == NULL) return this->val;

            // 如果当前的节点个数不为零，ans就更新为this->val
            if(this->cnt != 0) return this->right->query_front(val, this->val);
            else return this->right->query_front(val, ans);
        }
    }

    // 找后继
    int query_next(int val, int ans)
    {
        if(this->val <= val)
        {
            if(this->right == NULL) return ans;
            else return this->right->query_next(val, ans);
        }
        else
        {
            if(this->left == NULL) return this->val;

            if(this->cnt != 0) return this->left->query_next(val, this->val);
            else return this->left->query_next(val, ans);
        }
    }

    // 按值查找排名（这里返回的是排名 - 1 需要 + 1）
    int query_rank(int val)
    {
        if(this->left == NULL) return 0;

        if(val == this->val) return this->left->size;

        if(val < this->val) return this->left->query_rank(val);

        return (this->right->query_rank(val) + this->left->size + this->cnt);
    }

    // 按排名查找值
    int query_val(int rank)
    {
        if(this->left == NULL) return 0;

        if(this->left->size >= rank) return this->left->query_val(rank);

        if(this->left->size + this->cnt >= rank) return this->val;

        return this->right->query_val(rank - this->left->size - this->cnt);
    }
};

Node *tree = NULL;

int n;

void solve()
{

    n = read(); nums = 0;
    req(i, 1, n)
    {
        int op = read(), x = read();
        if(op == 5)
        {
            if(nums == 0) { nums++; tree = new Node(x); }
            else tree->insert(x);
        }
        else if(op == 1) printf("%d\n", tree->query_rank(x) + 1);
        else if(op == 2) printf("%d\n", tree->query_val(x));
        else if(op == 3) printf("%d\n", tree->query_front(x, -INTMAX));
        else if(op == 4) printf("%d\n", tree->query_next(x, INTMAX));
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