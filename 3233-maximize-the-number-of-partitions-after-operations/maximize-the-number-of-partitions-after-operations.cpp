class Solution {
public:
    // helper to count the number of times distinct characters that exceed k
    inline int countPartitions(const string& t, int k) {
        int partitions = 1;
        int mask = 0, distinct = 0;

        for (char c : t) {
            int bit = 1 << (c - 'a');
            if (!(mask & bit)) {
                mask |= bit;
                ++distinct;
            }
            if (distinct > k) {
                ++partitions;
                mask = bit;
                distinct = 1;
            }
        }
        return partitions;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        int maxAnswer = 0;
        array<int, 26> m = {0};
        for (int i = 0; i < n; ++i) {
            m[s[i] - 'a']++;
            array<int, 26> a;
            a.fill(INT_MAX);
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (m[ch - 'a'] > 0)
                    a[ch - 'a'] = -1;
            }
            for (int j = i + 1; j < n; ++j) {
                a[s[j] - 'a'] = min(a[s[j] - 'a'], j);
            }
            pair<int, char> mn = {INT_MIN, 'a'};
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                mn = max(mn, make_pair(a[ch - 'a'], ch));
            }
            char original = s[i];
            s[i] = mn.second;
            int currentAnswer = countPartitions(s, k);
            maxAnswer = max(maxAnswer, currentAnswer);
            s[i] = original;
        }

        return maxAnswer;
    }
};