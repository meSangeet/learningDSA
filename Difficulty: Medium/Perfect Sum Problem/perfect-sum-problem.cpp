//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int MOD = 1e9+7;
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
                // DP array initialized to 0
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        
        // Base case: There's one way to achieve a sum of 0, by choosing the empty subset
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        // Fill the dp array
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                // Exclude the current element
                dp[i][j] = dp[i-1][j];
                
                // Include the current element if it doesn't exceed the current sum
                if (arr[i-1] <= j) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j - arr[i-1]]) % MOD;
                }
            }
        }
        
        // The answer is the number of subsets that sum up to 'sum'
        return dp[n][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends