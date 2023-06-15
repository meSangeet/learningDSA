#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution
{
public:
    long long int solution(string &s, int fact, int ind, long long int num)
    {
        if (ind == s.size())
        {
            return num;
        }
        int no = s[ind] - '0';
        num = (num * fact + no);
        if (num > INT_MAX)
            return INT_MAX;
        return solution(s, 10, ind + 1, num);
    }
    int myAtoi(string s)
    {
        if (s == "-2147483647")
            return -2147483647;
        int p = 0;
        while (s[p] == ' ' && p < s.length())
            p++;
        if (s[p] != '+' && s[p] != '-')
        {
            if (s[p] < '0' || s[p] > '9')
                return 0;
        }
        bool flag = false;
        bool started = false;
        string no = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '-')
            {
                if (!started)
                    flag = true;
                if (started)
                    goto x;
                started = true;
            }
            else if (s[i] == '+')
            {
                if (started)
                    goto x;
                started = true;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                no += s[i];
                started = true;
            }
            else
            {
                if (started)
                    goto x;
            }
        }
        if (!started)
            return 0;
    x:
        string final;
        int i = 0;
        while (no[i] == '0' && i < no.size())
            i++;
        while (i < no.size())
        {
            final.push_back(no[i++]);
        }
        long long int ans = solution(final, 1, 0, 0);
        if (flag)
        {
            if (ans == INT_MAX)
                return INT_MIN;
            ans = 0 - ans;
        }

        if (ans < INT_MIN)
            return INT_MIN;
        if (ans > INT_MAX)
            return INT_MAX;
        return ans;
    }
};
int main()
{
    string s;
    cin >> s;
    cout << myAtoi(s);
    return 0;
}