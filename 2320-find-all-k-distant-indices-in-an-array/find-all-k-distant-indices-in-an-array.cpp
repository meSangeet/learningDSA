class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == key){
                s.insert(i);
                int j = i-1;
                while(abs(i-j) <= k and j >= 0){
                    s.insert(j);
                    j--;
                }
                j = i+1;
                while(abs(i-j) <= k and j < nums.size()){
                    s.insert(j);
                    j++;
                }
            }
        }

        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};