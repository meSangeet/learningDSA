class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> ball;
        map<int,int> m;
        vector<int> ans;
        for(int i = 0; i<queries.size(); i++){
            int b = queries[i][0];
            int color = queries[i][1];
            if(ball[b] != 0){
                m[ball[b]]--;
                if(m[ball[b]] == 0){
                    m.erase(ball[b]);
                }
                ball[b] = color;
                m[color]++;
            }else{
                ball[b] = color;
                m[color]++;
            }
            ans.push_back(m.size());
        }
        return ans;
    }
};