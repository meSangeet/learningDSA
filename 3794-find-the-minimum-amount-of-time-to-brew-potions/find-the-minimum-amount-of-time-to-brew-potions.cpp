class Solution {
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        //one potion has to brewed completely
        //potion - mana
        //wizard - skill
        //all wizard will pass through the potion 
        vector<ll> finTime(n,0);
        for(int i = 0; i<n; i++){
            if(i == 0){
                finTime[i] = skill[i]*mana[0];
            }else{
                finTime[i] = finTime[i-1] + skill[i]*mana[0];
            }
        }
        
        for(int j = 1; j < m; j++){
            //now we will do the same for all the potions
            vector<long long> temp(n, 0);
            for(int i = 0; i<n; i++){
                if(i == 0){
                    long long mul = skill[i] * mana[j];
                    temp[i] = finTime[i] + mul;
                }else{
                    long long mul = skill[i] * mana[j];
                    long long maxx = max(finTime[i], temp[i-1]);
                    temp[i] = maxx+mul;
                }
            }
            finTime[n-1] = temp[n-1];
            //now all the finTimes are updated now let's correct them
            for(int i = n-2; i >= 0; i--){
                long long mul = skill[i+1]*mana[j];
                finTime[i] = finTime[i+1] - mul;
            }
        }
        return finTime[n-1];
    }
};