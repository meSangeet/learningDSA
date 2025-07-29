class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& a) {
        int n = a.size();
        vector<int> res(n), last(32);
        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 32; ++b)
                if (a[i] & (1 << b))
                    last[b] = i;
            int mx = i;
            for (int j : last) mx = max(mx, j);
            res[i] = mx - i + 1;
        }
        return res;
    }
};
