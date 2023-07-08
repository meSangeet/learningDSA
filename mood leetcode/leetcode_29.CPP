#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()) return -1;
        int first = needle[0];
        int size = needle.length();
        for(int i = 0; i < haystack.length() - size + 1; i++)
        {
            if(haystack[i] == first)
            {
                bool flag = 0;
                for(int j = 0; j<size ;j++)
                {
                    if(haystack[i+j] != needle[j])
                    {
                        flag = 1;
                    }
                }
                if(flag == 0)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
  
int main()
{
    
    
    
    return 0;
}