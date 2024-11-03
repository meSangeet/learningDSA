class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //high level function -> f(i, tar) => number of possible combinations till ith element of the array if total sum needs to be tar
        //we need to find f(n-1, amount);
        vector<int> coin(coins);
        sort(coin.begin(), coin.end());
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long> (amount+1, 0));

        for(int i = 0; i<= amount; i++){
            if(i%coin[0] == 0){
                dp[0][i] = 1;
            }
        }

        for(int i = 0; i<n; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i<n; i++){
            for(int j = 1; j<=amount; j++){
                long long pick = 0, nonPick = 0;
                int took = 1;
                while(j >= took*coin[i] && pick < INT_MAX){
                    pick += dp[i-1][j - took*coin[i]];
                    took++;
                }

                nonPick = dp[i-1][j];
                if(pick < INT_MAX)
                dp[i][j] = pick + nonPick;
            }
        }

        return dp[n-1][amount];
    }
};