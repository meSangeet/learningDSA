class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> gandh(n, -1);
        vector<int> results;

        for(int i = 0; i<n; i++){

            if(i != 0){
                if(nums[i-1] != nums[i]-1){
                    gandh[i] = i-1;
                }else{
                    gandh[i] = gandh[i-1];
                }
            }

            if(i >= (k-1)){
                int lastGandh = gandh[i];
                if(lastGandh >= (i-k+1)){
                    results.push_back(-1);
                }else{
                    results.push_back(nums[i]);
                }
            }
        }

        return results;
    }
};