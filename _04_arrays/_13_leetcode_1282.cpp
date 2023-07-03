#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> m;
        for(int i = 0; i<groupSizes.size(); i++)
        {
            m[groupSizes[i]].push_back(i);
        }
        for(auto z: m)
 {
            int total = z.second.size();
            int siz = z.first;
            int times = total/siz;
            for(int i = 0; i<times; i++)
            {
                vector<int> temp;
                for(int j = 0; j<siz; j++)
                {
                    temp.push_back(z.second.back());
                    z.second.pop_back();
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}