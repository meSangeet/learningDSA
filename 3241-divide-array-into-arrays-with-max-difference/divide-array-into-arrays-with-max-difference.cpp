class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int n = nums.size();
        for(int i = 0; i<n-2; i += 3){
            if(temp[i+2] - temp[i] > k) return {};
            ans.push_back({temp[i], temp[i+1], temp[i+2]});
        }
        return ans;
    }
};