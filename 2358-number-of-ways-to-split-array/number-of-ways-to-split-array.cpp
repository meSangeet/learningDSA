class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        deque<long long> suffixSum;
        long long currentSum = 0;
        int n = nums.size();
        for(int i = n-1; i>=0; i--){
            currentSum += nums[i];
            suffixSum.push_front(currentSum);
        }

        currentSum = 0;

        int ans = 0;

        for(int i = 0; i<n-1; i++){
            currentSum += nums[i];
            if(currentSum >= suffixSum[i+1]) ans++;
        }

        return ans;
    }
};