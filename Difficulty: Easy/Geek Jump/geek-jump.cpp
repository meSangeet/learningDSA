//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if(n == 1) return 0;
        
        if(n == 2) return abs(height[1] - height[0]);
        
        int a = 0, b = abs(height[1]-height[0]);
        int ans;
        for(int i = 2; i<n; i++){
            int cur = height[i];
            ans = min(a + abs(cur - height[i-2]), b + abs(cur - height[i-1]));
            a = b;
            b = ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends