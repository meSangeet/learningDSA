class Solution {
    bool isPossible(char start, string s, string goal, int l, int i){
        //we will be iterating the string goal and s simultaneously. starting from the start of
        //the string goal and ith index of the string s

        for(int j = 0; j<l; j++){
            int indForS = j + i;
            indForS %= l;
            if(s[indForS] != goal[j]){
                return false;
            }
        }

        return true;
    }
public:
    bool rotateString(string s, string goal) {
        //start character
        int l = s.length(); 
        char start = goal[0];
        bool ans = false;
        for(int i = 0; i<l; i++){
            if(s[i] == start && isPossible(start, s, goal, l, i)){
                return true;
            }
        }

        return false;
    }
};