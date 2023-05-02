#include <bits/stdc++.h>
using namespace std;
    
int main()
{
    
    
    
    return 0;
}
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int i = 0;
        int count = 0;
        while(s[i] == ' ')
        {
            i++;
        }
        while(s[i] != ' ' && i<s.length())
        {
            count++;
            i++;
        }

        return count;
    }
};