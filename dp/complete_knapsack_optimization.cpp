#include <iostream>

using namespace std;

const int N = 1010;
int v[N], w[N];
int dp[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    // dp[j]表示前i件物品装进容量为j的背包的最大价值
    // dp[j] = max{dp[j], dp[j-v[i]] + w[i]}
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

    cout << dp[m] << endl;

    return 0;
}