//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
           int n = arr.size();
    
    // Edge case: If there's only one building or less, no steps can be made
    if (n <= 1) return 0;
    
    int max_steps = 0;  // To store the maximum number of steps
    int curr_steps = 0; // To store the current number of consecutive steps
    
    // Traverse the array and count consecutive steps with increasing altitude
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            curr_steps++;  // Increase the step count if the next building is taller
        } else {
            curr_steps = 0;  // Reset the step count if the altitude doesn't increase
        }
        max_steps = max(max_steps, curr_steps);  // Update the maximum steps
    }
    
    return max_steps;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends