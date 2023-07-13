#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool isSub(string s, string p, vector<int> &removable, int k)
    {
        for(int i = k; k>=0; k--)
        {
            s[i] = '.';
        }
        int i = 0, j = 0;
        while(j <= p.size()-1 && i<s.size())
        {
            if(s[i] == '.')
            {
                continue;
            }else if(i >= s.size()) return false;
            else{
                if(s[i] == p[j])
                {
                    i++;
                    j++;
                }else{
                    i++;
                }
            }
        }
        return true;
    }   
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int st = 0, e = removable.size() - 1;
        int ans = 0;
        int mid = st + (e-st)/2;
        while(st <= e)
        {
            if(isSub(s, p, removable, mid))
            {
                ans = mid;
                st = mid+1;
            }else{
                e = mid-1;
            }
            mid = st + (e-st)/2;
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}