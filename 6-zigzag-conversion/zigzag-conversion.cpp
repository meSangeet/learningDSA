class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= numRows || numRows < 2)
            return s;
        
        vector<string> strs(numRows, "");
        int idx = 0;
        bool fwd = true;

        for(int i = 0; i < s.size(); i++){
            strs[idx] += s[i];
            
            idx = fwd?(idx+1):(idx-1);
            
            if(idx == numRows-1){
                fwd = false;
            }else if(idx == 0){
                fwd = true;
            }
        }
        
        string combined;
        for(auto str: strs){
            combined += str;
        }

        return combined;
    }
};