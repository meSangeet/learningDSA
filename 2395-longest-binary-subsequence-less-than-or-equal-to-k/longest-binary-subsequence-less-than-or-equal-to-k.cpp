class Solution {
public:
    int longestSubsequence(string s, int k) {
        int num = 0;
        int ans = 0;
        int bit = 0;
        for(int i = s.length()-1; i>=0; i--){
            if(s[i] == '0'){
                ans++;
            }else{
                if(bit > 30){
                    continue;
                }
                int tba = pow(2, bit);
                if(num + tba <= k){
                    num += tba;
                    ans++;
                }
            }
            bit++;
        }
        return ans;
    }
};