#define ll long long
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        ll windowSum = 0;      
        ll maxFreq = 0;              
        ll left = 0;                 

        for (int right = 0; right < nums.size(); ++right) {
            windowSum += nums[right]; 
            
            while (nums[right] * (right - left + 1) - windowSum > k) {
                windowSum -= nums[left];
                ++left;
            }

            maxFreq = max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};
