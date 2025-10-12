class Solution {
public:
    static uint64_t quickmul(uint64_t x, uint64_t y, uint64_t mod_val) {
        uint64_t res = 1;
        uint64_t cur = x % mod_val;
        while (y > 0) {
            if (y & 1) {
                res = res * cur % mod_val;
            }
            y >>= 1;
            cur = cur * cur % mod_val;
        }
        return res;
    }
    
    int magicalSum(int m, int k, vector<int>& nums) {
        const uint64_t mod_val = 1000000007;
        const int n = nums.size();
        
        // Calculate factorials and their inverses
        vector<uint64_t> fac(m + 1);
        fac[0] = 1;
        for (int i = 1; i <= m; i++) {
            fac[i] = fac[i - 1] * i % mod_val;
        }
        
        vector<uint64_t> ifac(m + 1);
        ifac[0] = ifac[1] = 1;
        for (int i = 2; i <= m; i++) {
            ifac[i] = quickmul(i, mod_val - 2, mod_val);
        }
        for (int i = 2; i <= m; i++) {
            ifac[i] = ifac[i - 1] * ifac[i] % mod_val;
        }
        
        // Calculate powers of nums
        vector<vector<uint64_t>> nums_power(n, vector<uint64_t>(m + 1));
        for (int i = 0; i < n; i++) {
            nums_power[i][0] = 1;
            uint64_t num = nums[i] % mod_val;
            for (int j = 1; j <= m; j++) {
                nums_power[i][j] = nums_power[i][j - 1] * num % mod_val;
            }
        }
        
        // DP array
        vector<vector<vector<vector<uint64_t>>>> f(n, 
            vector<vector<vector<uint64_t>>>(m + 1, 
                vector<vector<uint64_t>>(m * 2 + 1, 
                    vector<uint64_t>(k + 1))));
        
        // Initialize first state
        for (int j = 0; j <= m; j++) {
            f[0][j][j][0] = nums_power[0][j] * ifac[j] % mod_val;
        }
        
        // DP transitions
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j <= m; j++) {
                for (int p = 0; p <= m * 2; p++) {
                    for (int q = 0; q <= k; q++) {
                        uint64_t current = f[i][j][p][q];
                        int q2 = (p % 2) + q;
                        if (q2 > k) break;
                        
                        for (int r = 0; r <= m - j; r++) {
                            int p2 = (p / 2) + r;
                            uint64_t add_val = current * nums_power[i + 1][r] % mod_val * ifac[r] % mod_val;
                            f[i + 1][j + r][p2][q2] = (f[i + 1][j + r][p2][q2] + add_val) % mod_val;
                        }
                    }
                }
            }
        }
        
        // Calculate final result
        uint64_t res = 0;
        for (int p = 0; p <= m * 2; p++) {
            for (int q = 0; q <= k; q++) {
                if (__builtin_popcount(p) + q == k) {
                    res = (res + f[n - 1][m][p][q] * fac[m] % mod_val) % mod_val;
                }
            }
        }
        
        return res;
    }
};
