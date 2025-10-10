#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int a[N];

void select_sort(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(a[i], a[min_idx]);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    select_sort(n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}