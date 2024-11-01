class Solution {
public:
    int tribonacci(int n) {
        //tabulation start from base case and move till nth index
        int a = 0, b = 1, c = 1;
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;

        int cur = a + b + c;
        for(int i = 3; i<=n; i++){
            cur = a + b + c;
            a = b;
            b = c;
            c = cur;
        }

        return cur;
    }
};