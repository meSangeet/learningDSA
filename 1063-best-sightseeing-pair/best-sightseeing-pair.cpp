class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxValToBeAdded = values[0];
        int ans = 0;
        for(int i = 1; i<values.size(); i++){
            maxValToBeAdded--;
            ans = max(ans,maxValToBeAdded + values[i]);
            maxValToBeAdded = max(maxValToBeAdded, values[i]);
        }
        return ans;
    }
};