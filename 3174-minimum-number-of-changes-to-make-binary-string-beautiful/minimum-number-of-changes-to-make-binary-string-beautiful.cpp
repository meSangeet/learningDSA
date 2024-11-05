class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int cur = 1;
        char prev = s[0];
        int l = s.length();
        for(int i = 1; i<l; i++){
            if(s[i] == prev){
                cur++;
            }else{
                if(cur%2){
                    ans++;
                    cur = 2;
                }else{
                    cur = 1;
                }
                prev = s[i];
            }
        }
        return ans;
    }
};