class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1, ' ');
        vector<string> words2 = split(sentence2, ' ');

        int i = 0;
        while (i < words1.size() && i < words2.size() && words1[i] == words2[i]) {
            i++;
        }

        int j = 0;
        while (j < words1.size() - i && j < words2.size() - i && words1[words1.size() - 1 - j] == words2[words2.size() - 1 - j]) {
            j++;
        }

        return i + j >= min(words1.size(), words2.size());
    }

private:
    vector<string> split(const string& s, char delimiter) {
        vector<string> result;
        stringstream ss(s);
        string word;
        while (getline(ss, word, delimiter)) {
            result.push_back(word);
        }
        return result;
    }
};
