#include <bits/stdc++.h>
using namespace std;

string toRoman(int n)
{
    /*
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    IV            4
    IX            9
    XL            40
    XC            90
    CD            400
    CM            900
    */

    unordered_map<int, string> m;
    m[0] = "";
    m[1] = "I";
    m[5] = "V";
    m[10] = "X";
    m[50] = "L";
    m[100] = "C";
    m[500] = "D";
    m[1000] = "M";
    m[4] = "IV";
    m[9] = "IX";
    m[40] = "XL";
    m[90] = "XC";
    m[400] = "CD";
    m[900] = "CM";
    int i = 1;
    deque<string> str;
    while (n != 0)
    {
        string curr = "";
        int temp = n % 10;
        int mul = temp * i;
        if (temp >= 5 && temp < 9)
        {
            curr += m[5 * i];
            int fac = temp - 5;
            while (fac--)
                curr += m[i];
        }
        else if (temp >= 1 && temp < 4)
        {
            curr += m[i];
            int fac = temp - 1;
            while (fac--)
                curr += m[i];
        }
        else
        {
            curr += m[mul];
        }
        str.push_front(curr);
        n /= 10;
        i *= 10;
    }
    string ans;
    for (int i = 0; i < str.size(); i++)
    {
        ans += str[i];
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
    cout << toRoman(n);
    return 0;
}
