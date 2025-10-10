class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        int temp = k;
        int ind = n-1;
        while(temp--){
            int cur = 0;
            for(int i = ind; i >= 0; i -= k){
                cur += energy[i];
                ans = max(ans, cur);
            }
            ind--;
        }
        return ans;
    }
};