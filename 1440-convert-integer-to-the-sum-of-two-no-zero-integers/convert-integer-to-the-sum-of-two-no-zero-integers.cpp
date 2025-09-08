class Solution {
public:
    bool check(int a, int b){
        while(a){
            if(a%10 == 0) return false;
            a /= 10;
        }

        while(b){
            if(b%10 == 0) return false;
            b /= 10;
        }

        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i <= n-1; i++){
            if(check(i, n-i)) return {i,n-i};
        }
        return {1, n-1};
    }
};