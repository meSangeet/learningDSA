class Solution {
public:
    string answerString(string word, int numFriends) {
        // The biggest possible string is of length:
        // len(word) - numFriends + 1
        std::string_view view = word;
        std::string biggest;
        
        if (numFriends == 1) {
            return word;
        }

        const int n = word.length() - numFriends + 1;

        for (int i = 0; i < word.length(); ++i) {
            // Create a string_view from i to min(end, )
            int end = std::min((int) word.length() - 1, i + n);
            const auto& sub = view.substr(i, n);
            if (sub > biggest) {
                biggest = sub;
            }
        }

        return biggest;
    }
};