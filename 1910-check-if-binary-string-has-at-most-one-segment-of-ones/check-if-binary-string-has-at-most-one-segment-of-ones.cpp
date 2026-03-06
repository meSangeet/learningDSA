class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;
        bool ff = false;
        for(char x : s){
            if(x == '1'){
                flag = true;
                if(ff) return false;
            }else{
                if(flag){
                    ff = true;
                }
            }
        }
        return true;
    }
};