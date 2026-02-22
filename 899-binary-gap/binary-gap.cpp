class Solution {
public:
    int binaryGap(int n) {
        int m, bitDist, prev = 1e9, maxDiff = 0;
        while(n){
            m = n ^ (n - 1);
            bitDist = log2(n & m);
            maxDiff = max(maxDiff, bitDist - prev);
            prev = bitDist;
            n = n ^ (1 << bitDist);
        }
        return maxDiff;
    }
};