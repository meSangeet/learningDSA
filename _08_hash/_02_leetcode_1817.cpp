#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_map<int,int>> m;
        for(int i = 0; i<logs.size(); i++)
        {
            m[logs[i][0]][logs[i][1]] = 1;
        }
        unordered_map<int,int> uam;
        for(auto x:m)
        {
            int temp = x.second.size();
            uam[temp]++;
        }
        vector<int> ans;
        for(int i = 0; i<k; i++)
        {
            ans.push_back(uam[i+1]);
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}