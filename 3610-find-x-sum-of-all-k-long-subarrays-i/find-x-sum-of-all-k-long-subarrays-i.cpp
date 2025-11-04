class Solution {
public:
    int find(vector<int>& count, int x) {
        vector<pair<int, int>> tmp;
        for (int i = 0; i <= 50; i++)
            if (count[i] > 0)
                tmp.push_back({count[i], i});

        sort(tmp.begin(), tmp.end(), [&](auto& a, auto& b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second > b.second;
        });
        int n = tmp.size(), res = 0;
        for (int i = 0; i < min(x, n); i++)
            res += (tmp[i].first * tmp[i].second);
        return res;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res, count(51, 0);
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
            if (i >= k - 1) {
                res.push_back(find(count, x));
                count[nums[i - k + 1]]--;
            }
        }
        return res;
    }
};