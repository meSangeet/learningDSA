class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char cur = '.';
        char prev = '.';
        int mx = 0;
        int count = 0;
        int ans = 0;
        int total = 0;
        int n = colors.size();
        for(int i = 0; i<n; i++){
            if(cur == '.'){
                prev = colors[i];
                total += neededTime[i];
                mx = neededTime[i];
                cur = prev;
                count++;
            }else{
                cur = colors[i];
                if(cur == prev){
                    count++;
                    total += neededTime[i];
                    mx = max(mx, neededTime[i]);
                }else{
                    if(count > 1){
                        ans += (total - mx);
                    }
                        total = neededTime[i];
                        mx = total;
                        count = 1;
                        prev = cur;
                }
            }
        }

        if(count > 1) ans += total - mx;

        return ans;
    }
};