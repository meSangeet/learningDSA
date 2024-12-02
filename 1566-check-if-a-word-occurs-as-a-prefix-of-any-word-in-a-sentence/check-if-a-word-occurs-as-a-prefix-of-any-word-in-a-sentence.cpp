class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = 0;
        int ind = 1;
        string curr = "";
        int n = sentence.length();
        while(i < n){
            if(sentence[i] == ' '){
                i++;
                curr = "";
                ind++;
                continue;
            }

            if(ind == -1){
                curr.push_back(sentence[i]);
                ind = i;
                if(curr == searchWord){
                    return ind;
                }
                i++;
                continue;
            }

            curr.push_back(sentence[i]);
            i++;
            if(curr == searchWord){
                return ind;
            }
        }

        return -1;
    }
};