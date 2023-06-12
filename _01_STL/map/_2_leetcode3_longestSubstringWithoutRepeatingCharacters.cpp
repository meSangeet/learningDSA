#include <bits/stdc++.h>
using namespace std;

    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        unordered_map<char,int> empty;
        int count = 0;
        int curr = 0;
        int i = 0;
        while(i < s.size())
        {
            curr++;
            if(m[s[i]] == 0)
            {
                m[s[i]] = 1;
                if(curr > count)
                {
                    count = curr;
                }
            }else{
                char temp = s[i];
                
                do{
                    i--;
                }while(temp != s[i]);
                m = empty;
                curr = 1;
                m[s[i]] = 1;
                if(curr > count)
                {
                    count = curr;
                }
            }
            i++;
        }
    return count;
    }

int main()
{
    cout<<lengthOfLongestSubstring("abcde");
    
    
    return 0;
}