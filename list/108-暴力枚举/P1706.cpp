/**
 * @file P1706.cpp
 * @author ozlinex
 * @brief P1706 全排列问题
 * @date 2023-07-09
 */

#include "header.hpp"
#include <iomanip>
#define MAXN 500001

ll n;

void dfs(int depth, vector<int>& path, vector<bool>& vis) {
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            cout << setw(5) << path[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            path.push_back(i);
            dfs(depth + 1, path, vis);
            path.pop_back();
            vis[i] = false;
        }
    }
}

void solve() {
    cin >> n;
    vector<int> path;
    vector<bool> vis(n + 1, false);
    dfs(0, path, vis);
}