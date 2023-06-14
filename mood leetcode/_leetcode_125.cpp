#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool isPali(string s, int st, int end)
    {
        while(st<end)
        {
            if(s[st++] != s[end--]) return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string str;
        for(long long int i = 0; i<s.length(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')  str.push_back(s[i]);
            if(s[i] >= 'A' && s[i] <= 'Z'){
                str.push_back(tolower(s[i]));
            }
            if(s[i] >= '0' && s[i] <= '9') str.push_back(s[i]);
        }
        bool flag = isPali(str, 0, str.length()-1);
        return flag;
    }
};

int main()
{
    
    return 0;
}