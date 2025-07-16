class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        for(int x : nums){
            if(x%2){
                c1++;
            }
            else{
                c2++;
            }
        }
        bool od1 = true, od2 = false;
        for(int i = 0; i<n; i++){
            if(c3 == 0){
                if(nums[i]%2){
                    c3++;
                }
            }else{
                if(od1){
                    if(nums[i]%2 == 0){
                        c3++;
                        od1 = false;
                    }
                }else{
                    if(nums[i]%2){
                        c3++;
                        od1 = true;
                    }
                }
            }

            if(c4 == 0){
                if(nums[i]%2 == 0){
                    c4++;
                }
            }else{
                if(od2){
                    if(nums[i]%2 == 0){
                        c4++;
                        od2 = false;
                    }
                }else{
                    if(nums[i]%2){
                        c4++;
                        od2 = true;
                    }
                }
            }
        }

        return max({c1,c2,c3,c4});
    }
};