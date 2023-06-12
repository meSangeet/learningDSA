class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> power;
        set<vector<int>> s;
        for(int i = 0; i<(1<<nums.size()); i++)
        {
            int mask = 1;
            vector<int> sub;
            for(int j = 0; j<nums.size(); j++)
            {
                if(i&(mask)) sub.push_back(nums[j]);
                mask <<= 1;
            }
            sort(sub.begin(), sub.end());
            s.insert(sub);
        }
        for(auto x:s)
        {
            power.push_back(x);
        }
        return power;
    }
};