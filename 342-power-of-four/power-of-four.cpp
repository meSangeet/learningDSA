#define ll long long
class Solution {
public:
    bool isPowerOfFour(int n) {
        ll i = 1;
        while(i <= n){
            if(i == n) return true;
            i *= 4;
        }
        return false;
    }
};