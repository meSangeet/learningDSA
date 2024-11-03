class Solution {
    void helper(int index, string &num, long long target, long long currValue, long long tail, string expression, vector<string> &result) {
        // Base case: If we've reached the end of the string
        if (index == num.size()) {
            // Check if the current expression evaluates to the target
            if (currValue == target) {
                result.push_back(expression);
            }
            return;
        }
        
        // Build each operand by adding one digit at a time
        for (int i = index; i < num.size(); i++) {
            // Skip numbers with leading zero
            if (i != index && num[index] == '0') break;

            // Get the current operand as a substring
            string currentStr = num.substr(index, i - index + 1);
            long long currentNum = stoll(currentStr);

            // If we're at the start, initialize the expression without any operator
            if (index == 0) {
                helper(i + 1, num, target, currentNum, currentNum, currentStr, result);
            } else {
                // Recursive call for addition
                helper(i + 1, num, target, currValue + currentNum, currentNum, expression + "+" + currentStr, result);

                // Recursive call for subtraction
                helper(i + 1, num, target, currValue - currentNum, -currentNum, expression + "-" + currentStr, result);

                // Recursive call for multiplication
                helper(i + 1, num, target, currValue - tail + tail * currentNum, tail * currentNum, expression + "*" + currentStr, result);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        helper(0, num, target, 0, 0, "", result);
        return result;
    }
};
