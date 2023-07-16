#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < s.length() && j < t.length())
        {
            if(s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        return i == s.length();
    }
};

int main()
{
    
    return 0;
}