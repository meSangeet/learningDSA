#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    int n, m;

    int numWays(vector<string>& words, string target) {
        m = target.size();
        n = words[0].size();
        vector<vector<ll>> dp(m+1, vector<ll> (n+1, 0));
        vector<vector<int>> count(26, vector<int>(n, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                char currentChar = word[j];
                int ind = currentChar - 'a';
                count[word[j] - 'a'][j]++;
            }
        }

        //writing the base 
        for(int i = 0; i<=n; i++) dp[0][i] = 1;

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                //not using the current column
                dp[i][j] = dp[i][j-1];

                //using the current column
                if(count[target[i-1] - 'a'][j-1] > 0){
                    dp[i][j] += dp[i-1][j-1]*(count[target[i-1] - 'a'][j-1]);
                }

                dp[i][j] %= MOD;
            }
        }


        return dp[m][n];
    }
};
