class Solution {
public:
    int numSteps(string s) {
        int result = 0;

        while (s.size() > 1) {
            if (s[s.size() - 1] == '0') {
                s.pop_back();
                result++;
                continue;
            }

            int indexOfZero = -1;

            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] == '0') {
                    indexOfZero = i;
                    break;
                }
            }

            if (indexOfZero != -1) {
                s[indexOfZero] = '1';
                for (int i = indexOfZero + 1; i < s.size(); i++)
                    s[i] = '0';
            } else {
                string temp = "1";
                for (int i = 1; i <= s.size(); i++)
                    temp += '0';
                s = temp;
            }

            result++;
        }

        return result;
    }
};