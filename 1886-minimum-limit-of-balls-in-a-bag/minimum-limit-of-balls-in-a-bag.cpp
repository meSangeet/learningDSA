class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 1;
        int hi = INT_MIN;
        for (int no : nums) {
            hi = max(no, hi);
        }
        
        int ans = hi;

        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            int ops = 0; 
            bool flag = true;
            
            for (int no : nums) {
                if (no > mi) {
                    ops += (no - 1) / mi;
                }
                if (ops > maxOperations) {  
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans = mi; 
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        }

        return ans;
    }
};
