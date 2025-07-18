class Solution {
public:
    using ll = long long int;
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size(), n = N / 3;
        vector<ll> maxSum(N, 0);
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0;
        for (int i = N - 1; i >= n; i--) {
            sum += nums[i];
            pq.push(nums[i]);
            if (pq.size() > n) {
                sum -= pq.top();
                pq.pop();
            }
            maxSum[i] = sum;
        }
        ll left = 0, res = LLONG_MAX;
        priority_queue<int> pql;
        for (int i = 0; i < 2 * n; i++) {
            left += nums[i];
            pql.push(nums[i]);
            if (pql.size() > n) {
                left -= pql.top();
                pql.pop();
            }
            if (i >= (n - 1)) {
                res = min(res, left - maxSum[i + 1]);
            }
        }
        return res;
    }
};