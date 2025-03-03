class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int e = 0, o = 0, n = nums.size();
        for(int x : nums){
            if(x%2) o++;
            else e++;
        }
        vector<int> ans;
        while(e--){
            ans.push_back(0);
        }
        while(o--){
            ans.push_back(1);
        }
        return ans;
    }
};