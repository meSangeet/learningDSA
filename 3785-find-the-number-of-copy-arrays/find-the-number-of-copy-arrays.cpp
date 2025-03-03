class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        //we need to find a hole
        int n = original.size();
        for(int i = 0; i<n-1; i++){
            int dif = original[i+1] - original[i];
            int a = bounds[i][0] + dif;
            int b = bounds[i][1] + dif;
            if(bounds[i+1][0] > b or bounds[i+1][1] < a) return 0;
            bounds[i+1][0] = max(a, bounds[i+1][0]);
            bounds[i+1][1] = min(b, bounds[i+1][1]);
        }
        return bounds[n-1][1] - bounds[n-1][0] + 1;
    }
};