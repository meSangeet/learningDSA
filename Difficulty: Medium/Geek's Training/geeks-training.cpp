//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<int> cur(3,0), prev(3,0);
        int maxx = 0;
        
        cur = arr[n-1];
        maxx = *max_element(cur.begin(), cur.end());
        
        prev = cur;
        
        for(int i = n-2; i>=0; i--){
            cur[0] = arr[i][0] + max(prev[1], prev[2]);
            cur[1] = arr[i][1] + max(prev[0], prev[2]);
            cur[2] = arr[i][2] + max(prev[0], prev[1]);
            
            maxx = max({cur[0], cur[1], cur[2]});
            
            prev = cur;
        }
        
        return maxx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends