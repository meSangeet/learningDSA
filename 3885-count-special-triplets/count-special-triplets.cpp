class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        using ll = long long;
        const int MOD = 1e9+7;
        unordered_map<int, ll> right, left;

        for (int x : nums) {
            right[x]++;
        }

        ll ans = 0;

        for (int x : nums) {
            right[x]--;

            ll target = (ll)x * 2;

            ll cl  = left.count(target) ? left[target] : 0;
            ll cr = right.count(target) ? right[target] : 0;

            ll add = (cl * cr) % MOD;
            ans = (ans + add) % MOD;

            left[x]++;
        }

        return (int)(ans % MOD);
    }
};