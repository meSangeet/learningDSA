class Solution {

    int findAnswer(int cur, int mb){
        int maax = pow(2,mb);
        int i = 0;
        int ans = 0;
        while(true){
            if((cur & 1) == 0){
                int temp = ans + pow(2,i);
                if(temp < maax){
                    ans = temp;
                }else{
                    break;
                }
            }
            cur >>= 1;
            i++;
        }
        return ans;
    }
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // vector<int> xorr;
        vector<int> ans;
        int cur = 0;
        for(int x : nums){
            cur ^= x;
            // xorr.push_back(cur);
            ans.push_back(findAnswer(cur, maximumBit));
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};