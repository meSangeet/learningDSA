class Solution {
public:
    long long coloredCells(int n) {
        long long fact = 4;
        long long ans = 1;
        for(int i = 2; i<=n; i++){
            ans += fact;
            fact += 4;
        }
        return ans;
    }
};