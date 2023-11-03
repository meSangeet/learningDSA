#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    string longestPalindrome(string s) {
    int f = 0, l = 0;
    int n = s.length();
    int ans = 1;
    for(int i = 0; i<n; i++)
    {
        int p = i-1, q = i+1;
        while(p >= 0 && q < n)
        {
            if(s[p] == s[q])
            {
                if((q-p+1) > ans)
                {
                    f = p;
                    l = q;
                }
                ans = max(ans, q-p+1);
                p--;
                q++;
            }else{
                break;
            }
        }
    }
    
    for(int i = 0; i<n-1; i++)
    {
        int j = i+1;
        if(s[i] == s[j])
        {
            if((j-i+1) > ans)
                {
                    f = i;
                    l = j;
                }
            ans = max(2, ans);
            int p = i-1, q = j+1;
        while(p >= 0 && q < n)
        {
            if(s[p] == s[q])
            {
                if((q-p+1) > ans)
                {
                    f = p;
                    l = q;
                }
                ans = max(ans, q-p+1);
                p--;
                q++;
            }else{
                break;
            }
        }
        }
    }
    string ap = "";
    for(int i = f; i<=l; i++)
    {
        ap.push_back(s[i]);
    }
    
    return ap;
    }
};

//main function
int main()
{

    return 0;
}