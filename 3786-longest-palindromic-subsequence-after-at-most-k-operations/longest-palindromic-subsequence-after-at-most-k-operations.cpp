class Solution {
public:
    int dist(char a, char b){
        int a1 = abs(a-b);
        int a2 = 26 - a1;
        return min(a1, a2);
    }

    int longestPalindromicSubsequence(string s, int k) {
        //dp[i][j][k] = longest palindromic subsequence in the string starting at ith index and ending at jth index with atmost k operations
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (k+1, 1)));
        //fill the base case -> answer for the single character string will be 1
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=k; j++){
                dp[i][i][j] = 1;
            }
        }

        //now the max length of string will be n
        for(int len = 2; len <= n; len++){
            //now we will increase lengths one by one 
            //also this will be done for all possible values of k
            for(int i = 0; i<n-len+1; i++){
                int st = i;
                int end = i + len - 1;
                //we are considering the string starting from st and ending at end
                //let's consider for all values of k
                for(int kk = 0; kk <= k; kk++){
                    if(len == 2){
                        int d = dist(s[st], s[end]);
                        if(d <= kk){
                            //it means this is possible
                            dp[st][end][kk] = 2;
                        }
                    }else{
                        //now we will have a subtring inside the start and ending indices
                        dp[st][end][kk] = dp[st+1][end-1][kk];
                        dp[st][end][kk] = max(dp[st][end][kk],dp[st][end-1][kk]);
                        dp[st][end][kk] = max(dp[st][end][kk],dp[st+1][end][kk]);
                        //now may be we will use some of the kk
                        int d = dist(s[st], s[end]);
                        if(d <= kk and kk-d >= 0 and st+1 <= end-1){
                            dp[st][end][kk] = max(dp[st][end][kk], dp[st+1][end-1][kk-d] + 2);
                        }
                    }
                }
            }
        }

        return dp[0][n-1][k];
    }
};
