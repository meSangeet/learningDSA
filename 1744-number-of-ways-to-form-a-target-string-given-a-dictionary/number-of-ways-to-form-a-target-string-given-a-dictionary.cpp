#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    int n, m;

    int countWays(int i, int j, const string& target, const vector<vector<int>>& count, vector<vector<ll>> &dp) {
        if (i == target.size()) return 1; 
        if (j == count[0].size()) return 0; 
        if(dp[i][j] != -1) return dp[i][j];
        //case 1
        int skip = countWays(i, j + 1, target, count, dp);
        //case2 - pick
        int use = 0;
        
        if (count[target[i] - 'a'][j] > 0) {
            use = (1LL * count[target[i] - 'a'][j] * countWays(i + 1, j + 1, target, count, dp)) % MOD;
        }
        return dp[i][j] = (skip + use) % MOD;
    }

    int numWays(vector<string>& words, string target) {
        m = target.size();
        n = words[0].size();
        vector<vector<ll>> dp(m+1, vector<ll> (n+1, -1));
        vector<vector<int>> count(26, vector<int>(n, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                char currentChar = word[j];
                int ind = currentChar - 'a';
                count[word[j] - 'a'][j]++;
            }
        }

        return countWays(0, 0, target, count, dp);
    }
};
