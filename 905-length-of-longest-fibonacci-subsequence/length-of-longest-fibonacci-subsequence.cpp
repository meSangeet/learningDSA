class Solution {
public:
    unordered_map<int, int> indexMap;  // Store index of each value
    vector<vector<int>> dp;  // Memoization table

    int recur(vector<int>& arr, int i, int j, int n) {
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 2;  // Start with at least two elements
        int nextValue = arr[i] + arr[j];

        if (indexMap.count(nextValue)) {
            int k = indexMap[nextValue];
            if (k > j) { // Ensure increasing indices
                ans = 1 + recur(arr, j, k, n);
            }
        }

        return dp[i][j] = ans;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        dp.assign(n, vector<int>(n, -1));

        // Store indices in hash map for quick lookup
        for (int i = 0; i < n; i++) {
            indexMap[arr[i]] = i;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, recur(arr, i, j, n));
            }
        }

        return ans >= 3 ? ans : 0;
    }
};