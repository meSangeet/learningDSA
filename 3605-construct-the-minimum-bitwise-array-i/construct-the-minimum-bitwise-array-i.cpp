class Solution {
public:
    
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        // x | (x+1) = a
        for(int a : nums){
            if(a%2 == 0){
                ans.push_back(-1);
                continue;
            }
            int temp = a;
            int no = 0;
            int fact = 0;
            bool flag = false;
            while(temp){
                if(flag){
                    if(temp&1){

                    }
                }else{
                    if(temp&1){
                        no += pow(2,fact);
                        fact++;
                    }else{
                        break;
                    }
                }
                temp >>= 1;
            }

            a -= no;
            no >>= 1;
            a += no;
            ans.push_back(a);
        }
        return ans;
    }
};