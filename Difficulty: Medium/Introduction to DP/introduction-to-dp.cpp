//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    const int mod = 1e9 + 7;
    long long int fibotopdown(int n, unordered_map<int,long long> &m){
        if(n == 0 || n == 1) return n;
        
        if(m[n] != 0) return m[n];
        return m[n] = (fibotopdown(n-1,m)+fibotopdown(n-2,m))%mod;
    }
  public:
    long long int topDown(int n) {
        unordered_map<int,long long> dp;
        return fibotopdown(n, dp);
        // code here
    }
    long long int bottomUp(int n) {
        // code here
        if(n == 0 || n == 1) return n;
        
        long long a = 0, b = 1;
        long long ans;
        for(int i = 2; i <= n; i++){
            ans = a + b;
            a = b;
            b = ans;
            ans %= mod;
            a %= mod;
            b %= mod;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends