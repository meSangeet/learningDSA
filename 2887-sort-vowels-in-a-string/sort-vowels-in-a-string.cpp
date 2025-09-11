class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> vowelList;
        
        for (char c : s) {
            if (vowels.find(c) != vowels.end()) {
                vowelList.push_back(c);
            }
        }
        
        sort(vowelList.begin(), vowelList.end());
        
        int idx = 0;
        string result;
        for (char c : s) {
            if (vowels.find(c) != vowels.end()) {
                result += vowelList[idx++];
            } else {
                result += c;
            }
        }
        
        return result;
    }
};