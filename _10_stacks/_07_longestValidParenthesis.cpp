#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxLength(string& str) {
        // Stack to store the indices of the parentheses
        stack<int> stk;
        
        // Pushing -1 initially to handle the base case where a valid substring starts from the beginning
        stk.push(-1);
        
        // Variable to store the maximum length of valid parentheses
        int max_len = 0;
        
        // Iterate through the string character by character
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '(') {
                // If the current character is an opening parenthesis, push its index onto the stack
                stk.push(i);
            } else {
                // If the current character is a closing parenthesis
                stk.pop(); // Pop the top of the stack (matching a '(' with ')')
                
                if (stk.empty()) {
                    // If the stack is empty after popping, push the current index as a base for future valid substrings
                    stk.push(i);
                } else {
                    // If the stack is not empty, calculate the length of the current valid substring
                    int current_len = i - stk.top();
                    max_len = max(max_len, current_len); // Update the maximum length if the current one is larger
                }
            }
        }
        
        return max_len; // Return the length of the longest valid parentheses substring
    }
};
