class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        stack<int> st;
        int j = 0;
        for(int a : nums){
            if(st.empty()){
                st.push(j);
            }
            if(nums[st.top()] > a){
                st.push(j);
            }
            j++;
        }

        int n = nums.size();
        for(int i = n-1; i>=0; i--){
            if(st.empty()){
                return ans;
            }

            if(nums[st.top()] <= nums[i]){
                ans = max(i-st.top(), ans);
                st.pop();
                i++;
            }
        }
        return ans;
    }
};