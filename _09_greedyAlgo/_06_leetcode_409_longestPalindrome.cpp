#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(int i = 0; i<s.length(); i++)
        {
            m[s[i]]+=1;
        }
        bool flag = false;
        int count = 0;
        for(auto x:m)
        {
            if(x.second % 2 == 1)
            {
                flag = true;
            }
            if(x.second % 2 == 0)
            {
                count += x.second;
            }else{
                count += x.second-1;
            }
        }
        if(flag) count++;
        return count;
    }
};

int main()
{
    
    return 0;
}