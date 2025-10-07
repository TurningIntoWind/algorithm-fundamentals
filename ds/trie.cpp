#include <iostream>

using namespace std;

const int N = 1e5 + 9;
int son[N][26], cnt[N], idx; // cnt存储以当前字符结尾的字符串数
char c, s[N];

void insert(char *str)
{
    int p = 0; // 根节点
    for (int i = 0; str[i] != '\0'; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> c >> s;
        if (c == 'I')
            insert(s);
        else
            cout << query(s) << endl;
    }

    return 0;
}