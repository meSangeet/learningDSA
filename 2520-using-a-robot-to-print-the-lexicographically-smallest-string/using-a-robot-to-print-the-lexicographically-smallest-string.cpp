class Solution {
public:
    string robotWithString(string s) {
       // To find min character after each position
        vector<char> min_after(s.length(), 'z' + 1);
        
        // If s is empty, return empty string
        if (s.empty()) return "";
        
        // Calculate the minimum character after each position
        min_after[s.length() - 1] = s[s.length() - 1];
        for (int i = s.length() - 2; i >= 0; i--) {
            min_after[i] = min(s[i], min_after[i + 1]);
        }
        
        string t = "";     // Robot's string
        string paper = ""; // Result string on paper
        int i = 0;         // Current position in s
        
        while (i < s.length() || !t.empty()) {
            // If t is empty or we can get a smaller char from s
            if (t.empty() || (i < s.length() && min_after[i] < t.back())) {
                t.push_back(s[i]);
                i++;
            } else {
                // Take from t and write to paper
                paper.push_back(t.back());
                t.pop_back();
            }
        }
        
        return paper;
    }
};