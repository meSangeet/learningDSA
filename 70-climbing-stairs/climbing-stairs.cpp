class Solution {
public:
    int climbStairs(int n) {
        const double phi = (1 + sqrt(5)) / 2;
        return round(pow(phi, n+1) / sqrt(5));
    }
};