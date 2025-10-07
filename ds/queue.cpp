#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 9;
int queue[N], hh, tt;
char s[10];

void push(int x)
{
    queue[tt++] = x;
}

void pop()
{
    ++hh;
}

void empty()
{
    if (hh == tt)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int query()
{
    return queue[hh];
}

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        cin >> s;
        if (strcmp(s, "push") == 0)
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (strcmp(s, "pop") == 0)
            pop();
        else if (strcmp(s, "empty") == 0)
            empty();
        else
            cout << query() << endl;
    }

    return 0;
}