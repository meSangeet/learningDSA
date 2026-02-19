class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        char cur = s[0];
        char prv = 'A';
        int curNo = 1;
        int prvNo = 0;
        int n = s.length();
        for(int i = 1; i < n; i++){
            if(s[i] == cur){
                curNo++;
                if(curNo <= prvNo) ans++;
            }else{
                cur = s[i];
                prvNo = curNo;
                curNo = 1;
                if(curNo <= prvNo) ans++;
            }
        }
        return ans;
    }
};