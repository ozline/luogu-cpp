/**
 * @author OZLIINEX
 * @brief P8306 【模板】字典树
 * @date 2023-01-23
 */

#include "header.hpp"
#define MAXN 1000001

struct Node
{
    int son[129];
    bool mark;
};

Node trie[MAXN];
int root, num;

bool trie_insert_check(char *str)
{
    int pos = root;
    for(int i = 0; str[i]; i++)
    {
        int x = str[i];
        if(!trie[pos].son[x]) trie[pos].son[x] = ++num; // 增加编号
        if(num > MAXN - 100)
        {
            debugvar(num);
            exit(0);
        }
        pos = trie[pos].son[x];
    }
    int temp = trie[pos].mark;
    trie[pos].mark = 1;

    return temp != 0;
}

bool trie_find(char *str)
{
    int pos = root;
    for(int i = 0; str[i]; i++)
    {
        int x = str[i] - 'a';
        if(!trie[pos].son[x]) return false;
        pos = trie[pos].son[x];
    }
    return true;
}

int n;
int ans;
char str[1501];

void solve()
{
    n = read();
    req(i, 1, n)
    {
        scanf("%s", str);
        if(!trie_insert_check(str)) ans++;
    }
    printf("%d\n", ans);
}