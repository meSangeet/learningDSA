class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> ans;
        for (long long x : nums) {
            ans.push_back(x);
            while (ans.size() > 1) {
                long long a = ans.back(); ans.pop_back();
                long long b = ans.back(); ans.pop_back();
                long long g = gcd(a, b);
                if (g == 1) {
                    ans.push_back(b);
                    ans.push_back(a);
                    break;
                } else {
                    ans.push_back((a / g) * b); // lcm
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
