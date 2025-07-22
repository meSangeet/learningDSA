class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> s;
        int ans = INT_MIN;
        int cur = 0;
        int n = nums.size();
        int las = 0;
        for(int i = 0; i<n; i++){
            int ele = nums[i];
            if(s.count(ele)){
                while(s.count(ele)){
                    s.erase(nums[las]);
                    cur -= nums[las];
                    las++;
                }
            }

            cur += ele;
            s.insert(ele);
            ans = max(ans, cur);
        }
        return ans;
    }
};