#include <iostream>
#include <deque>

using namespace std;

const int N = 1e6 + 9;
int a[N];

void get_min(int n, int k)
{
    deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        if (!dq.empty() && dq.front() + k - 1 < i)
            dq.pop_front();
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);

        if (i >= k)
            cout << a[dq.front()] << " ";
    }
}

void get_max(int n, int k)
{
    deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        if (!dq.empty() && dq.front() + k - 1 < i)
            dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);

        if (i >= k)
            cout << a[dq.front()] << " ";
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    get_min(n, k);
    puts("");
    get_max(n, k);

    return 0;
}