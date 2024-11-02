class Solution {
public:
    bool isCircularSentence(string sentence) {
        int l = sentence.length();
        if(sentence[0] != sentence[l-1]) return false;
        
        for(int i = 0; i<l; i++){
            if(sentence[i] == ' '){
                if(sentence[i-1] != sentence[i+1]){
                    return false;
                }
            }
        }

        return true;
    }
};