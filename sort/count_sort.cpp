#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 9;

int a[N], b[N], c[N]; // a待排序数组，b排序后的数组，c计数数组

void count_sort(int n, int k)
{
    // 计数 O(n)
    for (int i = 0; i < n; i++)
        c[a[i]]++;
    // 求前缀和，c[i]表示不大于i的元素个数 O(k)
    for (int i = 1; i < k; i++)
        c[i] += c[i - 1];
    // 排序 O(n)
    for (int i = n - 1; i >= 0; i--)
    {
        c[a[i]]--;
        b[c[a[i]]] = a[i];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    count_sort(n, *max_element(a, a + n) + 1);
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';

    return 0;
}
