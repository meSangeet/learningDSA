#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr = {pref[0]};
        for(int i = 1; i<pref.size(); i++)
        {
            arr.push_back((pref[i]^pref[i-1]));
        }
        return arr;
    }
};


int main()
{
    
    return 0;
}