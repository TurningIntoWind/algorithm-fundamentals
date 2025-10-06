#include <iostream>

using namespace std;

const int N = 1010;
int v[N], w[N];
int dp[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    // dp[i][j]表示前i件物品装进容量为j的背包的最大价值
    // dp[i][j] = max{dp[i-1][j], dp[i-1][j-v[i]] + w[i]}
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (j < v[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);

    cout << dp[n][m] << endl;

    return 0;
}