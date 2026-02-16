class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        int temp = n;
        int cnt = 31;
        while(n){
            if(n&1){
                ans += pow(2, cnt);
            }
            cnt--;
            n >>= 1;
        }
        return ans;
    }
};