class Solution {
    bool check(string str, string tar) {
        int n = tar.length();
        if (str.length() != n - 1) return false; // Ensure str is one character shorter than tar

        bool flag = false;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            if (ind < str.length() && str[ind] == tar[i]) {
                ind++; // Match the character in both strings
            } else {
                if (flag) return false; // If we've already skipped a character in tar, return false
                flag = true; // Mark that we skipped a character
            }
        }
        return true;
    }

public:
    static bool comp(string &a, string &b) {
        return a.length() < b.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp); // Sort words by length
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (check(words[j], words[i])) { // Check if words[j] can form words[i]
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }

        // Optional: For debugging purposes
        // for (auto x : dp) cout << x << " ";

        return ans;
    }
};
