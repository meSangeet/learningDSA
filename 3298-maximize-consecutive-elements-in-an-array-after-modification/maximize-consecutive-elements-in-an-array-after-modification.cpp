class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int cur = 1;
        for(int x : temp){
            cout<<x<<" ";
        }
        cout<<endl;
        // vector<vector<int>> dp(temp.back()+2, vector<int> (2, 0));
        // dp[0][0] = 1;
        // dp[0][1] = 1;
        vector<int> dp(temp.back()+2, 0);
        int ans = 1;
        for(int i = 0; i < temp.size(); i++){
            int elem = temp[i];
            // cout<<elem-1<<" -> "<<dp[elem-1]<<", "<<elem<<" -> "<<dp[elem]<<endl;
            dp[elem+1] = max(dp[elem]+1, dp[elem+1]);
            dp[elem] = max(dp[elem-1] + 1, dp[elem]);
            ans = max(ans, dp[elem+1]);
            ans = max(ans, dp[elem]);
            // cout<<dp[elem]<<" "<<dp[elem+1]<<endl;
        }

        return ans;
    }
};