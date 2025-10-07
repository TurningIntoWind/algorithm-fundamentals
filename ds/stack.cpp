#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 9;
int stk[N], top;
char s[10];

void push(int x)
{
    stk[top++] = x;
}

void pop()
{
    --top;
}

void empty()
{
    if (!top)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int query()
{
    return stk[top - 1];
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