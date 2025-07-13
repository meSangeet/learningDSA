class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = players.size();
        int n = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0, ans = 0;
        while(i < m and j < n){
            if(players[i] <= trainers[j]){
                ans++;
                i++;
                j++;
            }else{
                j++;
            }
        }

        return ans;
    }
};