#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:

    long long int usable(vector<int>&nums, vector<int>& cost, long long int median){

        long long ans = 0;
         for(int i=0;i<nums.size();i++)
           ans += abs(1ll*nums[i]-median)*(1ll*cost[i]);

         return ans;  
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {

        long long t = 0;
        long long sum = 0;
        int n = nums.size();

        vector<pair<int,int>> vec;

        for(int i=0;i<nums.size();i++)
            vec.push_back({nums[i],cost[i]});

        sort(vec.begin(),vec.end());

        for(int i=0;i<n;i++)
        sum += vec[i].second;

        long long median;
        int i=0;

        while(t < (sum+1)/2 && i<n){

             t += 1ll*vec[i].second;
             median = vec[i].first;
             i++;
        }    
        
        
        return usable(nums,cost,median);
    }
};

int main()
{
    
    return 0;
}