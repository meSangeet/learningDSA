class Solution {
public:
    int minimumLength(string s) {
        vector<int> vec(26,0);
        int n = s.length();
        for(char x : s){
            vec[x - 'a']++;
        }
        int ans = 0;
        for(int x : vec){
            if(x == 0) continue;
            if(x%2) ans++;
            else ans += 2;
        }
        return ans;
    }
};