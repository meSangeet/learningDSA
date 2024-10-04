class Solution {
public:

    bool divisionPossible(long long totalSkill, long long totalTeam){
        return (totalSkill%totalTeam)?false:true;
    }

    long long dividePlayers(vector<int>& skill) {
        long long totalSkill = accumulate(skill.begin(), skill.end(), 0ll);
        long long totalPlayers = skill.size();
        long long totalTeams = totalPlayers/2;
        if(!divisionPossible(totalSkill, totalTeams)) return -1ll;
        long long skillRequiredPerTeam = totalSkill/totalTeams;
        long long chemistry = 0;
        int presentInMap = 0;
        map<long, long> m;
        for(int x : skill){
            int needed = skillRequiredPerTeam - x;
            if(needed <= 0) return -1ll;
            if(x >= skillRequiredPerTeam) return -1ll;
            if(m[needed] > 0){
                chemistry += x*needed;
                m[needed]--;
                presentInMap--;
            }else{
                m[x]++;
                presentInMap++;
            }
        }

        if(presentInMap) return -1;

        return chemistry;
    }
};