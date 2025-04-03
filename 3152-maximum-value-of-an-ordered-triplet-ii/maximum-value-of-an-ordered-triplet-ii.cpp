#define ll long long 
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;
        ll gm = nums[0];
        ll ind = 1;
        while(ind < n and nums[ind] > gm){
          gm = nums[ind];
          ind++;
        }

        ll mx = gm - nums[ind];
        for(ll i = ind+1; i<n; i++){
          ll cv = mx * nums[i];
          ans = max(ans, cv);
          ll a = nums[i];
          mx = max(mx, gm - a);
          if(a > gm){
            gm = a;
          }
        }

        return ans;
    }
};