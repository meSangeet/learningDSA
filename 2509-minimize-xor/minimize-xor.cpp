class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Count set bits in num2
        int setBits = __builtin_popcount(num2);
        
        // Initialize result
        int x = 0;
        
        // First, try to match 1s in num1 from most significant to least
        // This minimizes XOR
        for(int bit = 31; bit >= 0 && setBits > 0; bit--) {
            if(num1 & (1 << bit)) {
                x |= (1 << bit);
                setBits--;
            }
        }
        
        // If we still have bits to set, place them in lowest unset positions
        // Starting from least significant bits
        if(setBits > 0) {
            for(int bit = 0; bit < 32 && setBits > 0; bit++) {
                if(!(x & (1 << bit))) {
                    x |= (1 << bit);
                    setBits--;
                }
            }
        }
        
        return x;
    }
};