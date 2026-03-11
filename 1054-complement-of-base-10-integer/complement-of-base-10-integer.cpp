class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;
        int i = 0;
        if(n == 0){
            return 1;
        }
        while(n){
            if((n&1)){
                ans |= (0<<i++);
            }else{
                ans |= (1<<i++);
            }
            n >>= 1;
        }
        return ans;
    }
};