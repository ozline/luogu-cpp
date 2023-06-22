/**
 * @author OZLIINEX
 * @brief 【深基16.例7】普通二叉树（简化版）
 * @date 2023-01-11
 */

// 实现一个BST，Binary Search Tree，二叉搜索树

// 但是最坏情况是会退化成一条链，这时候搜索复杂度就会达到最大，为了避免这个情况，我们会有了平衡树这一概念

// 完成时间是1月14号，中间经历了太多，不过最后还是实现了动态开点，节省了空间资源

#include "header.hpp"
#define MAXN 500001



struct Node
{
    Node *left, *right; // 左儿子 右儿子
    int val, cnt, size; // 值 当前值的个数 以该点为根的树的大小

    Node(int x):val(x),cnt(1),size(1){};

    // 插入，如果是第一个节点则直接使用new,不要用insert
    void insert(int x)
    {
        this->size++;
        if(x == this->val) { this->cnt++; return; }

        if (x < this->val)
        {
            if (this->left == NULL) this->left = new Node(x);
            else this->left->insert(x);
        }
        else
        {
            if (this->right == NULL) this->right = new Node(x);
            else this->right->insert(x);
        }
    }

    // 找前驱, def为缺省值（找不到时返回,default）
    int query_front(int val, int def)
    {
        if(val <= this->val)
        {
            if(this->left == NULL) return def;
            return this->left->query_front(val, def);
        }
        else
        {
            if(this->right == NULL) return this->val;
            return this->right->query_front(val, this->val);
        }
    }

    // 找后继, def为缺省值（找不到时返回,default）
    int query_next(int val, int def)
    {
        if(val < this->val)
        {
            if(this->left == NULL) return this->val;
            return this->left->query_next(val, this->val);
        }
        else
        {
            if(this->right == NULL) return def;
            return this->right->query_next(val, def);
        }
    }

    // 查找排名（这里返回的是排名 - 1 需要 + 1）
    int query_rank_byval(int val)
    {
        if(val == this->val)
        {
            if(this->left == NULL) return 0;
            return this->left->size;
        }

        if(val < this->val)
        {
            if(this->left == NULL) return 0;
            return this->left->query_rank_byval(val);
        }

        if(this->right == NULL) return this->size;
        else
        {
            int ans = this->right->query_rank_byval(val);
            if(this->left != NULL) ans += this->left->size;
            return (ans + this->cnt);
        }
    }

    // 根据排名查找值，如果没找到返回INF
    int query_val_byrank(int rank)
    {
        if(rank < 1) return INF;
        if(this->left != NULL)
        {
            if(this->left->size >= rank) return this->left->query_val_byrank(rank);

            if(this->left->size + this->cnt >= rank) return this->val;

            if(this->right != NULL) return this->right->query_val_byrank(rank - this->left->size - this->cnt);
        }
        else
        {
            if(this->cnt >= rank) return this->val;
            if(this->right != NULL) return this->right->query_val_byrank(rank - this->cnt);
        }
        return INF;
    }
};

Node *tree = NULL;

int n;

int op, x;

void solve()
{

    // n = read();
    scanf("%d", &n);
    req(i, 1, n)
    {
        // int op = read(), x = read();
        scanf("%d %d", &op, &x);
        if(op == 5)
        {
            if(tree == NULL) tree = new Node(x);
            else tree->insert(x);
        }
        else if(op == 1) printf("%d\n", tree->query_rank_byval(x) + 1);
        else if(op == 2) printf("%d\n", tree->query_val_byrank(x));
        else if(op == 3) printf("%d\n", tree->query_front(x, -2147483647));
        else if(op == 4) printf("%d\n", tree->query_next(x, 2147483647));
    }
    return;
}