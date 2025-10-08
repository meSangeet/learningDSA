class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = spells.size();
        sort(potions.begin(), potions.end());
        for(int i = 0; i<n; i++){
            //suc = spell * pot
            long long minPot = success / spells[i];
            if(minPot * spells[i] < success){
                minPot++;
            }
            auto it = lower_bound(potions.begin(), potions.end(), minPot);
            int rem = it - potions.begin();
            int in = potions.size() - rem;
            ans.push_back(max(0,in));
        }
        return ans;
    }
};