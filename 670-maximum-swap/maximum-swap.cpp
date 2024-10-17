class Solution {
public:
    int maximumSwap(int num) {
            // Convert the number into a string of digits for easy manipulation
    string digits = to_string(num);
    int n = digits.size();
    
    // Create an array to store the index of the maximum digit to the right of each digit
    vector<int> maxIdx(n);
    
    // Fill the maxIdx array, where maxIdx[i] will be the index of the largest digit
    // starting from i to the end
    int maxIndex = n - 1;
    maxIdx[maxIndex] = maxIndex;
    
    for (int i = n - 2; i >= 0; --i) {
        if (digits[i] > digits[maxIndex]) {
            maxIndex = i;
        }
        maxIdx[i] = maxIndex;
    }
    
    // Now find the first position where a swap will give a larger number
    for (int i = 0; i < n; ++i) {
        // If the current digit is smaller than the maximum digit to its right, swap
        if (digits[i] < digits[maxIdx[i]]) {
            // Swap digits[i] with digits[maxIdx[i]]
            swap(digits[i], digits[maxIdx[i]]);
            break;
        }
    }
    
    // Convert the modified digits string back to an integer and return it
    return stoi(digits);
    }
};