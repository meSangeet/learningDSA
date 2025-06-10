class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        int maxo = 0;
        int mine = 100;
        for(char x : s){
            freq[x - 'a']++;
        }
        for(int x : freq){
            if(x%2){
                maxo = max(x, maxo);
            }else{
                if(x > 0)
                mine = min(mine, x);
            }
        }

        return maxo - mine;
    }
};