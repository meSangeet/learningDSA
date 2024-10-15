//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int target) {
            unordered_map<int, int> prefixSumMap;
    
    int curr_sum = 0;  // Initialize cumulative sum
    int count = 0;     // Initialize count of subarrays
    prefixSumMap[0] = 1; // Handle case when a subarray starts from index 0
    
    for (int i = 0; i < arr.size(); i++) {
        curr_sum += arr[i];  // Update cumulative sum
        
        // Check if there's a prefix sum that matches (curr_sum - target)
        if (prefixSumMap.find(curr_sum - target) != prefixSumMap.end()) {
            count += prefixSumMap[curr_sum - target];  // Add the frequency of matching prefix sum
        }
        
        // Add the current cumulative sum to the map
        prefixSumMap[curr_sum]++;
    }
    
    return count;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends