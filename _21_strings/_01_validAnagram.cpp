#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26,0);
        for(int i = 0; i<s.length(); i++)
        {
            a[s[i]-'a']++;
        }

        for(int i = 0; i<t.length(); i++)
        {
            a[t[i]-'a']--;
        }

        for(int i = 0; i<26; i++)
        {
            if(a[i])
            {
                return false;
            }
        }

        return true;
    }
};

//main function
int main()
{

    return 0;
}