#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int n;
    bool good(int x , long long k , vector<int> &arr ){
        long long ct = 0;
        for(int i=0 ; i<n ; i++){
            ct += (arr[i]/x);
        }
        return (ct>=k);
    }
    int maximumCandies(vector<int>& arr, long long k) {
        int low = 1;
        int high = 1e9+1;
        n = arr.size();
        int ans = 0;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(good(mid , k , arr)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return ans;
    }
};

int main()
{
    
    return 0;
}