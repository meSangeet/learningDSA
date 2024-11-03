class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        /*
        a | b 
        n-1
        2^(n-1)

        f(i) -> this denotes answer for the array starting from the ith index

        starting from the last index, we will go to first
        
        target is to find the value of dp[0]
        */

        vector<int> dp(n+1, 0);

        //base case 
        dp[n-1] = arr[n-1];

        for(int i = n-2; i>=0; i--){
            int curSum = 0; //sum for curSubArray
            int len = 0;
            int maxElem = 0;
            for(int j = i; j < ((i+k)>n?n:(i+k)); j++){
                len++;
                maxElem = max(maxElem, arr[j]);
                curSum = maxElem*len;
                dp[i] = max(dp[i], curSum + dp[j+1]);
            }
        }

        return dp[0];
    }
};