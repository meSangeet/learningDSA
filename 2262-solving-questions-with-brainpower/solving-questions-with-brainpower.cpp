class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        //looks like a basic dp question

        //dp[i] -> maximum points you can gain if you start choice making from Ith question
        int n = questions.size();
        vector<long long> dp(n, 0);

        for(int i = n-1; i >= 0; i--){
            //either you can select the current question
            long long points1 = questions[i][0];
            long long additional1 = 0;
            long long nextInd = i + questions[i][1] + 1;
            if(nextInd < n){
                additional1 = dp[nextInd];
            }

            points1 += additional1;

            long long p2 = (i == n-1) ? 0 : dp[i+1];

            dp[i] = max(points1, p2);
        }

        return dp[0];
    }
};