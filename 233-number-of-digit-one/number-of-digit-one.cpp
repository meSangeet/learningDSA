class Solution {
    int dp[11][2][10];
public:
    int count(string num, int tight, int idx, int co){
        if(idx == num.size()){
            return co;
        }

        if(dp[idx][tight][co] != -1) return dp[idx][tight][co];

        int limit = tight ? num[idx] - '0' : 9;
        int res = 0;
        for(int d = 0; d <= limit; d++){
            int nc = co;
            if(d == 1) nc++;

            res += count(num, (tight ? (num[idx] - '0' == d) : 0), idx+1, nc);
        }

        return dp[idx][tight][co] = res;
    }

    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        string num = to_string(n);
        return count(num, 1, 0, 0);
    }
};