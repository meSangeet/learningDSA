long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> products;
        int fact = 0;
        while (n) {
            if (n & 1) {
                products.push_back(1 << fact); // 2^fact
            }
            fact++;
            n >>= 1;
        }

        const long long mod = 1e9+7;
        vector<long long> pre(products.size());
        pre[0] = products[0] % mod;
        for (int i = 1; i < products.size(); i++) {
            pre[i] = (pre[i-1] * products[i]) % mod;
        }

        vector<int> ans;
        for (auto &x : queries) {
            int a = x[0], b = x[1];
            long long res = pre[b];
            if (a > 0) {
                long long inv = modPow(pre[a-1], mod-2, mod); // modular inverse
                res = (res * inv) % mod;
            }
            ans.push_back((int)res);
        }
        return ans;
    }
};
