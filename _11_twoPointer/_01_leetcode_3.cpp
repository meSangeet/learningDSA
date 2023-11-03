#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> alpha;
        int i = 0, j = 0;
        int ans = 0;
        int curr = 0;
        while(i<s.length() && j < s.length())
        {
            while(j < s.length() && alpha[s[j]-'a'] == 0)
            {
                alpha[s[j]-'a'] = 1;
                curr++;
                j++;
            }

            ans = max(ans, curr);

            while(i<s.length() && s[i] != s[j])
            {
                alpha[s[i]-'a'] = 0;
                i++;
                curr--;
            }

            i++;
            curr--;
            if(j < s.length())
            alpha[s[j]-'a'] = 0;
        }

        return ans;
    }
};

//main function
int main()
{

    return 0;
}