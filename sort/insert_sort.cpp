#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int a[N];

void insert_sort(int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = a[i], j = i - 1;
        while (j >= 0 && a[j] > k)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insert_sort(n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}