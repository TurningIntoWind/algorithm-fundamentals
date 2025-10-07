#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1010, M = 2e6 + 9;

int v[N], w[N], s[N];
int dp[M];

vector<int> new_v, new_w; // 二进制分组后的物品

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];

    // 二进制分组
    for (int i = 1; i <= n; i++)
    {
        int k = 1;
        while (s[i] >= k)
        {
            new_v.push_back(k * v[i]);
            new_w.push_back(k * w[i]);
            s[i] -= k;
            k *= 2;
        }
        if (s[i])
        {
            new_v.push_back(s[i] * v[i]);
            new_w.push_back(s[i] * w[i]);
        }
    }

    // 01背包
    for (int i = 0; i < new_v.size(); i++)
        for (int j = m; j >= new_v[i]; j--)
            dp[j] = max(dp[j], dp[j - new_v[i]] + new_w[i]);

    cout << dp[m] << endl;

    return 0;
}