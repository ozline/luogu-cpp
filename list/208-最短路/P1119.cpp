/**
 * @author OZLIINEX
 * @brief P1119 灾后重建 Prim
 * @date 2022-07-18
 */


//Prim模板题？


#include "header.hpp"
#define MAXN 401

void solve()
{
    int n,m;
    cin>>n>>m;
    int t[MAXN];
    int dis[MAXN][MAXN];

    //根据题意，这个t表示这个点修好的时间
    memset(t,0,sizeof(t));
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
    }

    //建边，把没提供的边设为inf
    memset(dis,INF,sizeof(dis));
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v] = w;
        dis[v][u] = w;
        //由于是双向边，我们就把两个都设为边权
    }

    int q;
    cin>>q;
    int k=0;

    //q次询问
    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;

        //判断这个时间两个点有没有都建好
        if(t[x]>z || t[y]>z)
        {
            cout<<"-1"<<endl;
            continue;
        }

        //题目有一个重要信息，村庄每个点的建好时间是递增的
        //题目还有一个重要信息：数据保证t是不下降的

        //也就是说，对于第t天，我们只需要进行一次Prim
        //而每一天的不同就在于每一天可以使用的点是不一样的
        //因此我们从第一个点开始搜，一直搜到第k个点还没修好为止
        //这也是为什么把k这个变量放在外面
        //由于我们需要求第t天的最短路径，因此需要从第一天计算到第t天

        //而计算过程就是Prim，或者说dp？
        while(t[k]<=z&&k<n) //当前关注的第K个点
        {
            for(int i=0;i<n;i++) //from
            {
                for(int j=0;j<n;j++) //to
                {
                    //看看和从i->k->j近还是当前的已知答案近
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }

            k++;
        }

        if(dis[x][y]>=INF)
        {
            cout<<"-1"<<endl;
            continue;
        }

        cout<<dis[x][y]<<endl;
    }
}