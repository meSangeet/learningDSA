class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(nums.begin(), nums.end()) +
                     k; // this is to ensure arr sizer
        map<int, int> mp;
        unordered_map<int, int> freq; // to store the freq

        // now we have to traverse the num and store the freq of each ele
        // and also map the freq from l to r of the ele considering k for it

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxVal);

            // now map the freq of the l and r
            mp[l]++;
            mp[r + 1]--;

            // and also map the ele of nums , as may be that could share ans
            mp[nums[i]] += 0;
        }

        int res = 1;
        int cumSum = 0;

        // now for this one we have to iterate on map and get the cummSum from
        // the value

        for (auto it = mp.begin(); it != mp.end(); it++) {
            int target = it->first;
            it->second += cumSum;

            int targetFreq = freq[target]; // get the freq of the target key
            int needConversion = it->second - targetFreq;
            int maxpossibleFreq = min(needConversion, numOperations);
            res = max(res, targetFreq + maxpossibleFreq);

            cumSum = it->second;
        }
        return res;
    }
};