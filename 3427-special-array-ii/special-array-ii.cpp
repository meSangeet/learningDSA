class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        set<int> s;
        int n = nums.size();

        for(int i = 1; i<n; i++){
            int a = nums[i-1]%2;
            int b = nums[i]%2;
            if(a == b){
                s.insert(i);
            }
        }
        
        vector<bool> answer;

        int q = queries.size();

        for(int i = 0; i<q; i++){
            int a = queries[i][0];
            int b = queries[i][1];
            auto u = s.upper_bound(a);
            if(u == s.end()){
                answer.push_back(true);
                continue;
            }
            int ub = *u;
            if(ub <= b){
                answer.push_back(false);
            }else{
                answer.push_back(true);
            }
        }

        return answer;
    }
};