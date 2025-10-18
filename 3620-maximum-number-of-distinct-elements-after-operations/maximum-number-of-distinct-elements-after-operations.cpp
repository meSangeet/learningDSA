class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mini = INT_MIN;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int no = nums[i];
            //try to decrease
            int pno = no - k;
            if(pno > mini){
                mini = pno;
                ans++;
                continue;
            }

            //we will need atleast mini + 1
            int target = mini+1;
            if(target < no){
                mini = target;
                ans++;
                continue;
            }

            if(target <= no+k){
                mini = target;
                ans++;
            }
        }
        return ans;
    }
};