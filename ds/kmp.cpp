#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> get_next(const string &s)
{
    vector<int> next(s.size());
    next[0] = -1;
    int j = -1, i = 0;
    while (i < s.size() - 1)
    {
        if (j == -1 || s[i] == s[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }

    return next;
}

void kmp(const string &s, const string &p)
{
    vector<int> next = get_next(p);
    int i = 0, j = 0;
    while (i < s.size() && j < p.size())
    {
        if (j == -1 || s[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];

        if (j == p.size())
        {
            cout << i - j << ' ';
            j = next[j - 1];
            --i;
        }
    }
}

int main()
{
    string s, p;
    cin >> s >> p;
    kmp(s, p);

    return 0;
}