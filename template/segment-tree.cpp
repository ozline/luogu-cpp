/**
 * @author OZLIINEX
 * @brief 线段树类
 * @date 2022-07-25
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


/*

支持如下：

通用：注册线段树、上载值（push_up）、下载值（push_down）、取模运算
区间：区间加、区间乘、区间赋值
单点：单点加、单点乘、单点赋值
查询：单点值、区间和、区间最大值、区间最小值

注意：这份模板相对完整，完整的代价就是如果直接搬的话题会超时（P3368），需要进行一定的修改简化，例如这里给的一个乘法Lazytag、区间乘法、取模运算在部分题是不需要的

注意：对于一些操作，需要适当的更新push_down()函数，这不是通用的（或许可以做到通用？但那没必要吧）
*/

typedef long long ll;
using namespace std;

/* 线段树 */
class SegmentTree{
public:
    SegmentTree():p(998244353),maxn(100001)
    {
        this->init();
    }

    SegmentTree(int p,int maxn):p(p),maxn(maxn)
    {
        this->init();
    }

    void init()
    {
        // 提交评测的时候这个不能加上去，不知道为啥
        // if(a != nullptr) delete []a;
        // if(tree != nullptr) delete []tree;

        this->a = new int[maxn+1];
        this->tree = new Node[maxn*4+2];
    }


    /**
     * @brief 建立线段树
     *
     * @param node 节点
     * @param l 线段左
     * @param r 线段右
     */
    void build(int node, int l, int r)
    {
        tree[node].tag_mul = 1;
        tree[node].tag_add = 0;

        tree[node].left = l;
        tree[node].right = r;

        if(l == r) tree[node].sum = tree[node].min = tree[node].max = a[l];
        else
        {
            int mid = (l + r) >> 1;
            this->build(node*2, l, mid);
            this->build(node*2+1, mid+1, r);
            push_up(node);
        }
        tree[node].sum %= p;
    }

    /**
     * @brief 下传Lazy tag
     *
     * @param node 节点
     */
    void push_down(int node) //懒标记
    {
        if(tree[node].tag)
        {
            //乘法与加法
            tree[node*2].sum = ( tree[node*2].sum*tree[node].tag_mul + tree[node].tag_add*( tree[node*2].right - tree[node*2].left + 1) ) % p;
            tree[node*2+1].sum = ( tree[node*2+1].sum*tree[node].tag_mul + tree[node].tag_add*( tree[node*2+1].right - tree[node*2+1].left + 1) ) % p;

            tree[node*2].tag_mul = ( tree[node*2].tag_mul*tree[node].tag_mul ) % p;
            tree[node*2+1].tag_mul = ( tree[node*2+1].tag_mul*tree[node].tag_mul ) % p;

            tree[node*2].tag_add = ( tree[node*2].tag_add*tree[node].tag_mul + tree[node].tag_add ) % p;
            tree[node*2+1].tag_add = ( tree[node*2+1].tag_add*tree[node].tag_mul + tree[node].tag_add ) % p;

            tree[node].tag_mul = 1;
            tree[node].tag_add = 0;

            // //仅考虑加法
            // tree[node*2].sum += tree[node].tag_add*(tree[node*2].right - tree[node*2].left + 1);
            // tree[node*2+1].sum += tree[node].tag_add*(tree[node*2+1].right - tree[node*2+1].left + 1);

            // tree[node*2].tag_add += tree[node].tag_add;
            // tree[node*2+1].tag_add += tree[node].tag_add;

            // tree[node].tag_add = 0; //下传之后把自己的lazy标记为0

            // //仅考虑赋值
            // tree[node<<1].sum = tree[node].tag_num * ( tree[node<<1].right - tree[node<<1].left + 1 );
            // tree[node<<1|1].sum = tree[node].tag_num * ( tree[node<<1|1].right - tree[node<<1|1].left +1 );

            // tree[node<<1].tag_num = tree[node<<1|1].tag_num = tree[node].tag_num;

            tree[node<<1].tag = tree[node<<1|1].tag = true;
            tree[node].tag = false;
        }
    }

    /**
     * @brief 上载更新
     *
     * @param node 节点
     */
    void push_up(int node)
    {
        tree[node].sum = ( tree[node*2].sum + tree[node*2+1].sum ) % p;
        tree[node].max = std::max( tree[node*2].max , tree[node*2+1].max);
        tree[node].min = std::min( tree[node*2].min , tree[node*2+1].min);
    }

    /**
     * @brief 单点加
     *
     * @param node 节点
     * @param pos 位置
     * @param num 待加值
     */
    void single_add(int node,int pos, ll num)
    {
        if(tree[node].left == tree[node].right)
        {
            tree[node].sum += num;
            return;
        }

        push_down(node);

        int mid = (tree[node].left + tree[node].right) >> 1;
        if(pos <= mid) this->single_add(node*2, pos, num);
        if(pos > mid) this->single_add(node*2+1, pos, num);
        push_up(node);
    }

    /**
     * @brief 单点乘
     *
     * @param node 节点
     * @param pos 位置
     * @param num 待乘值
     */
    void single_mul(int node,int pos, ll num)
    {
        if(tree[node].left == tree[node].right)
        {
            tree[node].sum *= num;
            return;
        }

        push_down(node);

        int mid = (tree[node].left + tree[node].right) >> 1;
        if(pos <= mid) this->single_add(node*2, pos, num);
        if(pos > mid) this->single_add(node*2+1, pos, num);
        push_up(node);
    }

    /**
     * @brief 单点赋值
     *
     * @param node 节点
     * @param pos 位置
     * @param num 新的值
     */
    void single_set(int node,int pos, ll num)
    {
        if(tree[node].left == tree[node].right)
        {
            tree[node].sum = num;
            return;
        }

        push_down(node);

        int mid = (tree[node].left + tree[node].right) >> 1;
        if(pos <= mid) this->single_set(node*2, pos, num);
        if(pos > mid) this->single_set(node*2+1, pos, num);
        push_up(node);
    }

    /**
     * @brief 区间加
     *
     * @param node 节点
     * @param l 左区间
     * @param r 右区间
     * @param num 数值
     */
    void range_add(int node, int l, int r, ll num)
    {
        if( l <= tree[node].left && r >= tree[node].right)
        {
            tree[node].sum = ( tree[node].sum + num*( tree[node].right - tree[node].left + 1 ) ) % p;
            tree[node].tag_add = ( tree[node].tag_add + num ) % p;
            tree[node].tag = true;
            return;
        }

        push_down(node);

        int mid = ( tree[node].left + tree[node].right ) >> 1;
        if(l <= mid) range_add(node*2,l,r,num);
        if(r > mid) range_add(node*2+1,l,r,num);

        push_up(node);
    }

    /**
     * @brief 区间乘法
     *
     * @param node 节点
     * @param l 左区间
     * @param r 右区间
     * @param num 数字
     */
    void range_mul(int node, int l, int r, int num)
    {
        if( l <= tree[node].left && r >= tree[node].right)
        {
            tree[node].sum = ( tree[node].sum * num ) % p;
            tree[node].tag_mul = ( tree[node].tag_mul * num ) % p;
            tree[node].tag_add = ( tree[node].tag_add * num ) % p;
            tree[node].tag = true;
            return;
        }

        push_down(node);

        int mid = ( tree[node].left + tree[node].right ) >> 1;
        if(l <= mid) range_mul(node*2,l,r,num);
        if(r > mid) range_mul(node*2+1,l,r,num);

        push_up(node);
    }

    /**
     * @brief 区间赋值
     *
     * @param node 节点
     * @param l 左区间
     * @param r 右区间
     * @param num 新数字
     */
    void range_set(int node, int l, int r, int num)
    {
        if( l <= tree[node].left && r >= tree[node].right )
        {
            tree[node].sum = ( tree[node].right - tree[node].left +1 ) * num;
            tree[node].tag_num = num;
            tree[node].tag = true;
            return;
        }

        push_down(node);

        int mid = (tree[node].left+tree[node].right)>>1;
        if( l <= mid ) this->range_set(node<<1, l, r, num);
        if( r > mid ) this->range_set(node<<1|1, l, r, num);
        push_up(node);
    }

    /**
     * @brief 单点查询
     *
     * @param node 节点
     * @param pos 待查询位置
     * @return ll 该位置的值
     */
    ll query_single(int node, int pos)
    {
        if(tree[node].left == tree[node].right) return tree[node].sum;

        push_down(node);

        int mid = (tree[node].left + tree[node].right) >> 1;
        ll ans = 0;
        if(pos <= mid) ans = this->query_single(node*2,pos);
        else ans = this->query_single(node*2+1,pos);

        return ans;
    }

    /**
     * @brief 区间和查询
     *
     * @param node 节点
     * @param x 左区间
     * @param y 右区间
     * @return ll 该区间的和
     */
    ll query_range(int node, int l, int r)
    {
        if(l <= tree[node].left && r >= tree[node].right) return tree[node].sum;

        push_down(node);

        int mid = ( tree[node].left + tree[node].right ) >> 1;
        ll ans = 0;
        if(l <= mid) ans += query_range(node*2,l,r);
        if(r > mid) ans += query_range(node*2+1,l,r);

        return ans % p;
    }

    /**
     * @brief 区间最大值
     *
     * @param node 节点
     * @param l 当前左位置
     * @param r 当前右位置
     * @return ll 区间答案
     */
    ll query_range_max(int node, int l, int r)
    {
        if(l <= tree[node].left && r >= tree[node].right) return tree[node].max;

        push_down(node);

        int mid = ( tree[node].left + tree[node].right ) >> 1;
        ll ans = -(1LL << 60);
        if(l <= mid) ans = max(ans , query_range_max(node*2, l, r));
        if(r > mid) ans = max(ans, query_range_max(node*2+1, l, r));

        return ans;
    }

    /**
     * @brief 区间最小值
     *
     * @param node 节点
     * @param l 当前左位置
     * @param r 当前右位置
     * @return ll 区间答案
     */
    ll query_range_min(int node, int l, int r)
    {
        if(l <= tree[node].left && r >= tree[node].right) return tree[node].min;

        push_down(node);

        int mid = ( tree[node].left + tree[node].right ) >> 1;
        ll ans = (1LL << 60);
        if(l <= mid) ans = min(ans , query_range_min(node*2, l, r));
        if(r > mid) ans = min(ans, query_range_min(node*2+1, l, r));

        return ans;
    }

    int *a;         //需要初始化的数组，这一部分可以改进，但是有点懒zzz

private:

    struct Node     //线段树节点结构
    {
        int left;   //左儿子
        int right;  //右儿子
        ll sum;     //线段和
        bool tag;   //lazy tag更新标志，为真时push_down()函数才可使用
        ll tag_mul; //乘法意义上的lazy tag
        ll tag_add; //加法意义上的lazy tag
        ll tag_num; //赋值意义上的lazy tag
        ll min;     //该区间最小值
        ll max;     //该区间最大值
    };

    ll maxn;        //最大尺寸
    Node *tree;     //线段树
    int p;          //模数
};
/* 线段树 */