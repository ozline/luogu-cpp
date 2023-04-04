
typedef long long ll;

/*

对于一个数组：a[maxn]，我们用c[maxn]这个数组来维护它

与线段树类似，c[maxn]维护一部分的a[maxn]或c[maxn]的值


*/

/* 树状数组 */
class FenwickTree
{
public:
    FenwickTree():maxn(100001)
    {
        this->init();
    }

    FenwickTree(int maxn):maxn(maxn)
    {
        this->init();
    }

    void init()
    {
        tree = new ll[maxn+1];
        a = new int[maxn+1];

        for(int i=1;i<=maxn;i++)
        {
            tree[i] = 0;
            a[i] = 0;
        }
    }

    /**
     * @brief 建树
     *
     * @param n 大小
     */
    void build(int n)
    {
        for(int i=1; i<=n; i++)
        {
            tree[i] += a[i];
            int j = i + this->lowbit(i);
            if(j <=n) tree[j] += a[i];
        }
    }

    int lowbit(int x)
    {
        // x 的二进制表示中，最低位的 1 的位置。
        // lowbit(0b10110000) == 0b00010000
        //          ~~~^~~~~
        // lowbit(0b11100100) == 0b00000100
        //          ~~~~~^~~
        return x & (-x);
    }

    /**
     * @brief 单点修改
     *
     * @param x 位置
     * @param k 值
     */
    void add(int x, int k)
    {
        while(x<=maxn)
        {
            tree[x] += k;
            x += lowbit(x);
        }
    }

    /**
     * @brief 前缀求和
     *
     * @param x 1..x的和
     * @return 前缀和
     */
    ll query(int x)
    {
        ll ans = 0;
        while( x >= 1)
        {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }

private:
    int maxn;
    ll *tree;
    int *a;
};
/* 树状数组 */