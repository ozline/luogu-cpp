/**
 * @author OZLIINEX
 * @brief P2024 [NOI2001] 食物链 POJ - 1182
 * @date 2022-04-28
 */

#include "header.hpp"
#define MAXN 100001

pair<ll, ll> node[MAXN]; // first：根节点位置 second:与根节点的关系（0=同类，1=吃，2=被吃）

/**
 * @brief 构建一个新的树
 */
void makeSet(ll n)
{
    for (int i = 1; i <= n; i++)
    {
        node[i].first = i;
        node[i].second = 0; //跟自己肯定是同类拉
    }
}

/**
 * @brief 查找x所在树的根节点，并不断更新这棵树
 */
ll find(ll x)
{
    ll fx = node[x].first; //拿到这个点的父节点
    if (x != fx)
    {
        node[x].first = find(fx);                                //持续更新这个节点的父节点
        node[x].second = (node[x].second + node[fx].second) % 3; //更新这个节点和父节点的关系
    }
    return node[x].first;
}

void Union(ll x,ll y,ll d){
    ll fx = find(x);
    ll fy = find(y);

    node[fy].first = fx;
    node[fy].second = (node[x].second - node[y].second + 3 + (d - 1)) % 3; //更新节点关系
}

void solve()
{
    ll n, k;
    ll aniType, aniX, aniY; //种类，动物1和2  1=同类 2=X吃Y
    ll ans = 0;
    scanf("%lld %lld", &n, &k);
    makeSet(MAXN - 1);
    while (k--)
    {
        scanf("%lld %lld %lld", &aniType, &aniX, &aniY);

        //当前的话中X或Y比N大 或 当前的话表示X吃X
        if (aniX > n || aniY > n || (aniX == aniY && aniType == 2))
        {
            ans++;
            continue;
        }
        if (find(aniX) == find(aniY)) //判断这两棵树的根节点是否一样，若不一样则执行合并操作，一样则进行相应判断
        {
            if (aniType == 1 && node[aniX].second != node[aniY].second) //同类但是两个根节点不同，false
                ans++;
            if (aniType == 2 && (node[aniX].second + 1) % 3 != node[aniY].second) //a吃b但是二者
                ans++;
        }
        else Union(aniX,aniY,aniType);
    }

    printf("%lld\n", ans);//
    return 0;
}