class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int a = -1, b = -1;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(a == -1){
                a = nums[i];
            }else if(b == -1){
                if(nums[i] > a){
                    b = nums[i];
                }else{
                    b = a;
                    a = nums[i];
                }
            }else{
                if(nums[i] <= a){
                    b = a;
                    a = nums[i];
                }else if(nums[i] < b){
                    b = nums[i];
                }
            }
        }

        return nums[0] + a + b;
    }
};