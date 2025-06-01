class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        for(int a=0; a<= min(n,limit); a++){
            int rem = n - a;
            if(rem > (2*limit)) continue;
            int b = min(limit, rem);        
            int c = max(0, rem-limit);      
            ans += (b - c + 1);
        }

        return ans;
    }
};