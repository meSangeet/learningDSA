class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(n == 1){return 0;}
        vector<vector<long long>> sums(2, vector<long long> (n, 0));
        long long cur1 = 0, cur2 = 0;
        for(int i = 0; i<n; i++){
            cur1 += grid[1][i];
            cur2 += grid[0][n-i-1]; 
            sums[1][i] = cur1;
            sums[0][n-i-1] = cur2;
        }

        long long ans = LLONG_MAX-10;
        for(int i = 1; i < n-1; i++){
            // cout<<i<<endl;
            long long sel = max(sums[1][i-1], sums[0][i+1]);
            ans = min(ans, sel);
        }
        if(n > 1){
            ans = min(ans, sums[0][1]);
            ans = min(ans, sums[1][n-2]);
        }
        
        return ans;
    }
};