class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0, z = 0;
        vector<int> temp;
        for(auto x : nums){
            total += x;
            if(x != 0){
                temp.push_back(x);
            }else{
                z++;
            }
        }

        if(z == nums.size()){
            if(target == 0){
                return pow(2,z);
            }
            return 0;
        }

        //f(i, tar) -> shows that no of expressions we can have till the ith index which will have eval equals to tar.
        int n = temp.size();
        //goal -> f(n-1, target)
        vector<vector<int>> dp(n, vector<int> (total + 1, 0));
        // cout<<"Temp - ";
        // for(auto x : temp) cout<<x<<" ";
        for(int i = 1; i <= total; i++){
            if(temp[0] == i){
                dp[0][i] = 1;
            }
        }
        
        for(int i = 0; i<n; i++){
            if(temp[i] == 0){
                dp[i][0] += 2;
            }else{
                dp[i][0]++;
            }
        }

        //f(i, tar) = if(i < tar) never pick we will only do the not pick operation and otherwise we can do both pick and non pick
        //pick -> f(i-1, tar - nums[i]) Non Pick -> f(i-1, tar).    dp[i][tar] = pick + non pick

        for(int i = 1; i < n; i++){
            for(int j = 1; j<=total; j++){
                int pick = 0, nonPick = 0;
                //pick
                if(j >= temp[i]){
                    pick = dp[i-1][j - temp[i]];
                }
                //non pick
                nonPick = dp[i-1][j];

                dp[i][j] = pick + nonPick;
            }
        }

        // cout << "\n DP array \n";
        // for(auto x : dp){
        //     for(auto y:x) cout<<y<<" ";
        //     cout<<endl;
        // }
        int ans = 0;
        for(int i = 0; i<total+1; i++){
            int rem = total - i;
            int count = dp[n-1][i];

            if((i - rem) == target){
                ans += count*pow(2,z);
            }
        }
        return ans;
    }
};