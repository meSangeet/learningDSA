//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    bool fun(vector<int> &arr, int i, int tar, vector<vector<int>> &dp){
        if(tar < 0) return false;
        if(tar == 0) return true;
        if(i == 0){
            if(tar == arr[0]) return true;
            return false;
        }
        
        if(dp[i][tar] != -1) return dp[i][tar];
        
        //pick
        bool c1 = fun(arr, i-1, tar-arr[i], dp);
        
        //not pick
        bool c2 = fun(arr, i-1, tar, dp);
        
        return dp[i][tar] = c1 or c2;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return fun(arr, n-1, sum, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends