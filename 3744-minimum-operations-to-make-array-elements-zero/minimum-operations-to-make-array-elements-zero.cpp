class Solution {
public:

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        for(auto &q : queries){
            int l = q[0];
            int r = q[1];

            long long steps = solve(l, r);
            ans += (steps + 1) / 2;
        }

        return ans;
    }

    long long solve(int l, int r){
        long long L = 1, S = 1, steps = 0;

        while(L <= r){
            long long R = 4 * L - 1;

            int start = max(L, (long long) l);
            int end = min(R, (long long) r);

            if(start <= end) steps += (end - start + 1) * S;
            S++;
            L *= 4;
        }

        return steps;
    }
};