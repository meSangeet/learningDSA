class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string s2 = s + s;

        int mismatch1 = 0;          // mismatch with pattern "010101..."
        int mismatch2 = 0;          // mismatch with pattern "101010..."

        int ans = INT_MAX;
        int start = 0;

        for (int end = 0; end < n+n; end++) {       // length of s2 = n+n
            int expected1 = (end % 2) ? '0' : '1';
            int expected2 = (end % 2) ? '1' : '0';

            if (s2[end] != expected1)
                mismatch1++;
            if (s2[end] != expected2)
                mismatch2++;

            if (end - start + 1 > n) {      // greater than window of size n
                expected1 = (start % 2) ? '0' : '1';
                expected2 = (start % 2) ? '1' : '0';

                if (s2[start] != expected1)
                    mismatch1--;
                if (s2[start] != expected2)
                    mismatch2--;

                start++;
            }

            // for every window of size n
            if (end - start + 1 == n)
                ans = min({ans, mismatch1, mismatch2});
        }
        return ans;
    }
};