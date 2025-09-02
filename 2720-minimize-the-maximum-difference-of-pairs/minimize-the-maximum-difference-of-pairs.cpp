class Solution {
public:
    bool canFormPairs(vector<int>& nums, int p, int diff) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        
        while(i < n-1 && count < p) {
            if(nums[i+1] - nums[i] <= diff) {
                count++;
                i += 2;
            }
            else {
                i++;
            }
        }
        
        return count >= p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.back() - nums[0];
        int result = right;
        
        while(left <= right) {
            int mid = left + (right - left)/2;
            
            if(canFormPairs(nums, p, mid)) {
                result = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return result;
    }
};
