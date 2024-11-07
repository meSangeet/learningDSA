class Solution {
    bool checkSetBit(int n, int b){
        if((n >> b)&1) return true;
        return false;
    }
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCount(26, 0);
        int ans = 0;
        for(int b = 0; b < 26; b++){
            for(int i = 0; i<candidates.size(); i++){
                if(checkSetBit(candidates[i],b)){
                    bitCount[b]++;
                }
            }
            ans = max(bitCount[b], ans);
        }
        return ans;
    }
};