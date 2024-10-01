class Solution {
public:
    int rob(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];
    
    int prev2 = arr[0];
    int prev1 = max(arr[0], arr[1]);
    
    for (int i = 2; i < n; i++) {
        int current = max(prev1, prev2 + arr[i]);
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
    }
};