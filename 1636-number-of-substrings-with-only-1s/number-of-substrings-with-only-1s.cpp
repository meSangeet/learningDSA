class Solution {
public:
    long long mod = 1e9+7;
    long long calc(int n){
        long long ans = n;
        ans *= (n+1);
        ans /= 2;
        ans %= mod;
        return ans;
    }
    int numSub(string s) {
        int cur = 0;
        long long ans = 0;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] == '1') cur++;
            else{
                if(cur == 0) continue;
                ans += calc(cur);
                ans %= mod;
                cur = 0;
            }
        }

        if(cur != 0){
            ans += calc(cur);
            ans %= mod;
        }

        return (int) ans;
    }
};