/**
 * @file P1065.cpp
 * @author ozlinex
 * @brief P1065 [NOIP2006 提高组] 作业调度方案
 * @date 2023-07-14
 */


// 我觉得是一个挺难的模拟，但是洛谷给的难度标只有普及+/提高
// 首先需要认真的理解题意，在此基础上，只需要做模拟就好
// 我们对每一个工序，在它指定的机器上做遍历（从这个工件的timeline开始）

// 对于未来回顾代码的我来说，比较难理解的应该是timeline[MAXN]这个东西
// timeline[i]指的是第i个工件加工完已经加工的工序后，总时间上的位置
// 比如你在第1s加工长度为2s的工序，那么加工完，timeline就是3
// 代表我们需要从时间3开始往后查找下一个工序插入的位置

#include "header.hpp"
#define MAXN 50

int m, n;                       // m个机器，n个工件
int order[MAXN * MAXN];         // 安排顺序
int machine[MAXN][MAXN];        // 第i个设备的第j道工序机器号
int cost[MAXN][MAXN];           // 第i个设备第j个工序耗时
int cnt[MAXN];                  // 第i个工件当前进度
int vis[MAXN][MAXN * 201];      // 第i个机器访问情况
int timeline[MAXN];             // 第i个工件当前加工到的时间位置

int ans;

void solve()
{
    cin >> m >> n;
    req(i, 1, m * n) cin >> order[i];
    req(i, 1, n) req(j, 1, m) cin >> machine[i][j];
    req(i, 1, n) req(j, 1, m) cin >> cost[i][j];

    req(i, 1, m * n) // 按顺序走每个工件
    {
        int cur = order[i]; // 当前需要安排的工件
        cnt[cur]++;         // 当前工件走到的工序号

        int curcost = cost[cur][ cnt[cur] ];       // 加工耗时
        int curmachine = machine[cur][ cnt[cur] ]; // 机器号

        // 临时计算长度、工序起点下标、工序结束下标
        int tmplen = 0, startindex = 0, endindex = 0;
        req(j, timeline[cur] + 1, MAXN * 200)
        {
            tmplen = vis[curmachine][j] ? 0 : tmplen + 1;

            if(tmplen == curcost){
                startindex = j - curcost + 1, endindex = j;
                break;
            }
        }

        // 覆盖这部分
        req(j, startindex, endindex) vis[curmachine][j] = 1;
        timeline[cur] = endindex; // 更新当前工件加工的时间
        ans = max(ans, timeline[cur]);
    }
    cout << ans << endl;
}