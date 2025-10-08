#include <iostream>
#include <algorithm>

const int N = 1e5 + 9;
int n, m, size;
int a[N];

// 下坠调整小根堆
void down(int u)
{
    int t = u;
    if (u * 2 <= size && a[u * 2] < a[t])
        t = u * 2;
    if (u * 2 + 1 <= size && a[u * 2 + 1] < a[t])
        t = u * 2 + 1;
    if (t != u)
    {
        std::swap(a[u], a[t]);
        down(t);
    }
}

int main()
{
    std::cin >> n >> m;
    size = n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    // 构造小根堆
    for (int i = n / 2; i > 0; i--)
        down(i);

    for (int i = 1; i <= m; i++)
    {
        std::cout << a[1] << " ";
        std::swap(a[1], a[size--]);
        down(1);
    }

    return 0;
}