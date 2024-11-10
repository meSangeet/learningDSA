class Solution {

    void removeBits(int a, vector<int> &bits){
        int i = 0;
        while(a){
            if((a&1)){
                bits[i]--;
            }
            i++;
            a /= 2;
        }
    }

    void addBits(int a, vector<int> &bits){
        int i = 0;
        while(a){
            if((a&1)){
                bits[i]++;
            }
            i++;
            a /= 2;
        }
    }

    int calculateNo(vector<int> &bits){
        int no = 0;
        for(int i = 0; i<64; i++){
            if(bits[i] > 0){
                no += pow(2,i);
            }
        }
        return no;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int cur = 0;
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> bits(64);
        int last = 0;
        int len = 0;
        for(int i = 0; i<n; i++){
            addBits(nums[i], bits);
            len++;
            if(calculateNo(bits) >= k){
                ans = min(ans, len);
                while(calculateNo(bits) >= k && last <= i){
                    ans = min(ans, len);
                    removeBits(nums[last], bits);
                    last++;
                    len--;
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};