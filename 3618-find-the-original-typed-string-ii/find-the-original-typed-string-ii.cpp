class Solution {
private:
    const int MODULO = 1e9 + 7;
    
public:
    int possibleStringCount(string word, int k) {
        int len = word.length();
        
        // Extract consecutive character counts
        vector<int> charCounts;
        int currentCount = 1;
        int idx = 1;
        
        while (idx < len) {
            if (word[idx] != word[idx - 1]) {
                charCounts.push_back(currentCount);
                currentCount = 1;
            } else {
                currentCount++;
            }
            idx++;
        }
        charCounts.push_back(currentCount);
        
        // Calculate total possibilities
        long long totalPossibilities = 1;
        for (auto count : charCounts) {
            totalPossibilities = (totalPossibilities * count) % MODULO;
        }
        
        int numGroups = charCounts.size();
        if (numGroups >= k) {
            return (int)totalPossibilities;
        }
        
        // Dynamic programming arrays
        vector<int> dpCurrent(k, 0);
        vector<int> prefixSum(k, 1);
        dpCurrent[0] = 1;
        
        for (int groupIndex = 0; groupIndex < numGroups; groupIndex++) {
            vector<int> dpNext(k, 0);
            
            for (int position = 1; position < k; position++) {
                dpNext[position] = prefixSum[position - 1];
                int boundary = position - charCounts[groupIndex] - 1;
                if (boundary >= 0) {
                    dpNext[position] = (dpNext[position] - prefixSum[boundary] + MODULO) % MODULO;
                }
            }
            
            vector<int> newPrefixSum(k, 0);
            newPrefixSum[0] = dpNext[0];
            for (int position = 1; position < k; position++) {
                newPrefixSum[position] = (newPrefixSum[position - 1] + dpNext[position]) % MODULO;
            }
            
            dpCurrent = dpNext;
            prefixSum = newPrefixSum;
        }
        
        return (int)((totalPossibilities - prefixSum[k - 1] + MODULO) % MODULO);
    }
};