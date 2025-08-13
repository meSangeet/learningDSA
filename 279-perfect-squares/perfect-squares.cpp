class Solution {
public:
    int numSquares(int n) {
        //n can only go upto 10^4 the max square will go to 10^2
        vector<int> numbers;
        int i = 1;
        while(i*i <= n){
            numbers.push_back(i*i);
            if(i*i == n) return 1;
            i++;
        }
        int sz = numbers.size();
        //now we need to select the numbers from the vector numbers
        //dp[i][j] -> minimum number of ways of getting to target j using the numbers 
        //at the first i indexes

        vector<vector<int>> dp(numbers.size(), vector<int> (n+1, INT_MAX));
        vector<int> mintn(n+1, INT_MAX);
        mintn[0] = 0;
        //targeting 0 will always need 0 numbers
        // for(auto x : numbers) cout<<x<<" ";
        // cout<<endl<<endl;
        for(int i = 0; i <= sz-1; i++){
            dp[i][0] = 0;
        }
        int mm = 0;
        //now for every target, current element can be selected or not
        for(int tar = 1; tar <= n; tar++){
            int mn = INT_MAX;
            for(int i = 0; i <= sz-1; i++){
                int elem = numbers[i];
                //elem can be selected or not
                //case 1 : selected
                //selection is only possible if tar is greater than or equal to elem
                int rem = tar - elem;
                if(tar >= elem and mintn[rem] != INT_MAX){
                    dp[i][tar] = min(dp[i][tar], mintn[rem]+1);
                }

                //case2 : don't select
                // dp[i][tar] = min(dp[i][tar],mintn[tar]);
                // cout<<dp[i][tar]<<" ";
                mn = min(mn, dp[i][tar]);
            }
            // cout<<endl;

            mintn[tar] = mn;
            // cout<<mn<<" ";
        }
        // cout<<endl;

        return mintn[n];
    }
};