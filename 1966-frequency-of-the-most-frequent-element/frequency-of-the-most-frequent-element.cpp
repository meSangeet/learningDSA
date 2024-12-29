#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        long long windowSum = 0;      
        int maxFreq = 0;              
        int left = 0;                 

        for (int right = 0; right < nums.size(); ++right) {
            windowSum += nums[right]; 
            
            while ((long long)nums[right] * (right - left + 1) - windowSum > k) {
                windowSum -= nums[left];
                ++left;
            }

            maxFreq = max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};
