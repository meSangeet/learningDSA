class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int mm = INT_MIN;
        set<int> s;
        int ans = INT_MIN;
        for(int x : nums){
            if(x < 0){
                mm = max(mm, x);
            }else{
                if(s.count(x)) continue;
                s.insert(x);
                if(ans == INT_MIN){
                    ans = x;
                }else{
                    ans += x;
                }
            }
        }
        return max(ans, mm);
    }
};