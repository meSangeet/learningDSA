class Solution {
public:
    bool checkPrime(int n){
        if(n == 1){
            return false;
        }
        for(int i = 2; i*i <= n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int l = -1, r = -1;
        int ans = INT_MAX;
        vector<int> temp = {-1,-1};
        for(int i = left; i<=right; i++){
            if(checkPrime(i)){
                if(l == -1){
                    l = i;
                }else{
                    if(r == -1){
                        r = i;
                        ans = r - l;
                        temp = {l,r};
                        l = i;
                    }else{
                        if(i - l < ans){
                            ans = i-l;
                            temp = {l,i};
                            l = i;
                        }
                        l = i;
                    }
                }
            }
        }
        return temp;
    }
};