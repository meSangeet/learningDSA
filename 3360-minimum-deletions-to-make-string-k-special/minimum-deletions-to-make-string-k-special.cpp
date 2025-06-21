class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end());

        int totalChars = accumulate(freq.begin(), freq.end(), 0);
        int ans = INT_MAX;

        for (int target = 1; target <= 100000; ++target) {
            int deletions = 0;
            for (int f : freq) {
                if (f == 0) continue;
                if (f > target + k) {
                    deletions += f - (target + k);
                } else if (f < target) {
                    deletions += f; // delete all, can't raise it
                }
                // if in [target, target + k] → do nothing
            }
            ans = min(ans, deletions);
        }

        return ans;
    }
};
