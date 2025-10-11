#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int a[N];

void insert_sort_binary(int n)
{
    for (int i = 1; i < n; i++)
    {
        // 二分寻找插入位置
        int k = a[i], l = 0, r = i - 1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (a[mid] < a[i])
                l = mid + 1;
            else
                r = mid - 1;
        }
        for (int j = i - 1; j >= l; j--)
            a[j + 1] = a[j];
        a[l] = k;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insert_sort_binary(n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}