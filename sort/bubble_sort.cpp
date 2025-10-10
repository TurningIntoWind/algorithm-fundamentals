#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 9;

int a[N];

void bubble_sort(int n)
{
    bool swapped = true;
    for (int i = 0; i < n - 1 && swapped; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bubble_sort(n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}