#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        for(int i = 1; i<numRows; i++)
        {
            vector<int> temp = {1};
            for(int j = 1; j<i; j++)
            {
                int ad = ans[i-1][j-1] + ans[i-1][j];
                temp.push_back(ad);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}