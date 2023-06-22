/**
 * @author OZLIINEX
 * @brief P1101 填涂颜色
 * @date 2023-03-24
 */


// 再提醒一次！不要fastio()后又特么的去用scanf和printf！！！
// 又浪费了时间

#include "header.hpp"
#define MAXN 500001

const char list[] = "yizhong";
int get_index(char ch)
{
    for(int i = 0; i < 8; i++)
        if (list[i] == ch) return i;
    return -1; // not found
}

int n;
char a[201][201];
int b[201][201]; // 0=not visit, 1=normal

int pos_x[] = {0, 0, 1, 1, 1, -1, -1, -1};
int pos_y[] = {1, -1, 0, 1, -1, 0, 1, -1};

bool dfs(int x, int y, char ch, int px, int py)
{
    if(ch == 'g')
    {
        b[x][y] = 1;
        return true;
    }

    int idx = get_index(ch);

    if(idx == -1) return false;

    if(x + px > n || x + px < 1 || y + py > n || y + py < 1) return false;
    if(a[x + px][y + py] != list[idx + 1]) return false;

    return b[x][y] = dfs(x + px, y + py, list[idx + 1], px, py) ? 1 : b[x][y];
}

void solve()
{
    cin >> n;
    req(i, 1, n) req(j, 1, n) cin >> a[i][j];

    req(i, 1, n) req(j, 1, n)
    {
        if(a[i][j] == 'y')
        {
            req(k, 0, 7) dfs(i, j, 'y', pos_x[k], pos_y[k]);
        }
    }

    req(i, 1, n)
    {
        req(j, 1, n)
        {
            if(!b[i][j]) cout << '*';
            else cout << a[i][j];
        }
        putchar('\n');
    }

    return;
}