class Solution {
public:
    int candy(vector<int>& ratings) {
        //I think I have seen this question somewhere

        vector<int> sangeetTravels(ratings.size(), 1);
        for(int i = 1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                sangeetTravels[i] = 1 + sangeetTravels[i-1];
            }
        }
        int ans = sangeetTravels.back();
        for(int i = ratings.size()-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                sangeetTravels[i] = max(sangeetTravels[i], 1 + sangeetTravels[i+1]);
            }
            ans += sangeetTravels[i];
        }
        return ans;
    }
};