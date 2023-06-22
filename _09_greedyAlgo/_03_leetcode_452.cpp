#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
   bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}
    int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    for(int i = 0; i<points.size(); i++)
    {
        cout<<"["<<points[i][0]<<","<<points[i][1]<<"] ";
    }
        vector<vector<int>> ans;
        ans.push_back(points[0]);
        for(int i = 1; i<points.size(); i++)
        {
            if(ans.back()[1] < points[i][0])
            {
                ans.push_back(points[i]);
            }else{
                ans.back()[1] = min(points[i][1], ans.back()[1]);
            }
        }
        cout<<endl;
        for(int i = 0; i<ans.size(); i++)
    {
        cout<<"["<<ans[i][0]<<","<<ans[i][1]<<"] ";
    }
        return ans.size();
    }
};

int main()
{
    
    return 0;
}