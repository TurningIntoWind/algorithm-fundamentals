#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 9;
int a[N];

void quick_sort(int l, int r)
{
    if (l >= r)
        return;

    int x = a[(l + r) >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        while (a[++i] < x)
            ;
        while (a[--j] > x)
            ;

        if (i < j)
            swap(a[i], a[j]);
    }

    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    quick_sort(0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}