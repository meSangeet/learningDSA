class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> m;
        for(auto x:arr){
            m[x]++;
        }
        int ii = 1;
        for(auto x:m){
            m[x.first] = ii;
            ii++;
        }
        vector<int> ans(arr.size());
        for(int i = 0; i<arr.size(); i++){
            ans[i] = m[arr[i]];
        }
        return ans;
    }
};