#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        for(int i = 0; i<intervals.size(); i++)
        {
            swap(intervals[i][0], intervals[i][1]);
        }
        sort(intervals.begin(), intervals.end());
        int count = 0;
        vector<vector<int>> diff;
        diff.push_back(intervals[0]);
        cout<<endl;
        for(int i = 1; i<intervals.size(); i++)
        {
            if(diff.back()[0] > intervals[i][1]){
                count++;
            }
            else{
                diff.push_back(intervals[i]);
            }
        }
        return count;
    }
};

int main()
{
    
    return 0;
}