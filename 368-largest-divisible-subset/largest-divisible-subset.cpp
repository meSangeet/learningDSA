class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> arr(nums);
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1);
        vector<int> prev(n,-1);
        int maxInd = 0;
        for(int i = 1; i<n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0){
                    if(1 + dp[j] > dp[i]){
                        dp[i] = 1 + dp[j];
                        prev[i] = j;
                    }
                }
            }
            if(dp[i] > dp[maxInd]){
                maxInd = i;
            }
        }

        vector<int> ans;

        while(maxInd != -1){
            ans.push_back(arr[maxInd]);
            maxInd = prev[maxInd];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};