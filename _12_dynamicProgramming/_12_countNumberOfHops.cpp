//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    const long int m = 1e9 + 7;
    long long countWays(int n)
    {
        
        // your code here
        vector<long long> dp(n+1,0);
        dp[n] = 1;
        for(int i = n-1; i>=0; i--)
        {
            long long case1 = 0, case2 = 0, case3 = 0;
            if(i+1<n+1)
            {
                case1 = dp[i+1];
            }
            if(i+2<n+1){
                case2 = dp[i+2];
            }
            if(i+3<n+1){
                case3 = dp[i+3];
            }
            
            dp[i] = (case1 + case2 + case3)%m;
        }
        
        return dp[0];
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends