#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898
bool checkValidString(string s)
{
    stack<int> brackets;
    stack<int> stars;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            brackets.push(i);
        if (s[i] == '*')
            stars.push(i);
        if (s[i] == ')')
        {
            if (!brackets.empty())
            {
                brackets.pop();
            }
            else if (!stars.empty())
            {
                stars.pop();
            }
            else
            {
                return false;
            }
        }
    }
    while (!brackets.empty())
    {
        if (stars.empty())
            return false;
        int a = brackets.top();
        int b = stars.top();
        if (b < a)
        {
            return false;
        }
        else
        {
            stars.pop();
            brackets.pop();
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (checkValidString(s))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}