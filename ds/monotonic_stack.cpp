#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

const int N = 1e5 + 9;
int a[N], ans[N];
int main()
{
    memset(ans, -1, sizeof ans);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    stack<int> stk; // 栈底存放最小值
    for (int i = n; i > 0; i--)
    {
        while (!stk.empty() && a[stk.top()] > a[i])
        {
            ans[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    return 0;
}