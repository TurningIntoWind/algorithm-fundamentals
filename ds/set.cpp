#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 9;

int f[N], c[N]; // c记录每个集合的点数，仅根节点有效

int find(int u)
{
    if (f[u] != u)
        return f[u] = find(f[u]);
    return u;
}

void Union(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    f[fy] = fx;
    c[fx] += c[fy];
}

int main()
{
    int n, m, a, b;
    string s;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        f[i] = i;
        c[i] = 1;
    }

    while (m--)
    {
        cin >> s >> a;
        if (s == "Q2")
            cout << c[find(a)] << endl;
        else
        {
            cin >> b;
            if (s == "C")
                Union(a, b);
            else
            {
                if (find(a) == find(b))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        }
    }

    return 0;
}