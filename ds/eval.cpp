#include <iostream>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

int cal(int x, int y, char p)
{
    if (p == '+')
        return x + y;
    if (p == '-')
        return x - y;
    if (p == '*')
        return x * y;
    if (p == '/')
        return x / y;
}

int pri(char p)
{
    if (p == '*' || p == '/')
        return 2;
    if (p == '+' || p == '-')
        return 1;
    return 0; // 左括号优先级为0
}

void func(stack<int> &OPND, stack<char> &OPTR)
{
    int o2 = OPND.top();
    OPND.pop();
    int o1 = OPND.top();
    OPND.pop();
    OPND.push(cal(o1, o2, OPTR.top()));
    OPTR.pop();
}

int main()
{
    string exp;
    cin >> exp;
    stack<int> OPND;  // 操作数栈
    stack<char> OPTR; // 运算符栈

    int i = 0;
    while (i < exp.size())
    {
        if (isdigit(exp[i]))
        {
            int val = exp[i] - '0';
            while (isdigit(exp[++i]))
                val = val * 10 + exp[i] - '0';
            OPND.push(val);
        }
        else if (exp[i] == '(')
        {
            OPTR.push('(');
            i++;
        }
        else if (exp[i] == ')')
        {
            while (!OPTR.empty() && OPTR.top() != '(')
                func(OPND, OPTR);
            OPTR.pop(); // 弹出左括号
            i++;
        }
        else
        {
            while (!OPTR.empty() && pri(OPTR.top()) >= pri(exp[i]))
                func(OPND, OPTR);
            OPTR.push(exp[i++]);
        }
    }

    while (!OPTR.empty())
        func(OPND, OPTR);

    cout << OPND.top() << endl;

    return 0;
}