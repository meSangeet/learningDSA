class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
            int n = nums.size() - 2;  // The actual range of numbers is 0 to n-1
    vector<int> freq(n, 0);   // Frequency array of size n to count occurrences
    vector<int> result;       // Result array to store the sneaky numbers
    
    // Count the frequency of each number in the input nums array
    for (int num : nums) {
        freq[num]++;
    }
    
    // Check which numbers appear exactly twice
    for (int i = 0; i < n; i++) {
        if (freq[i] == 2) {
            result.push_back(i);
        }
    }
    
    return result;
    }
};