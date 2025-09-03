class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        auto lamda = [](vector<int>& p1,vector<int>& p2){
            return p1[0]==p2[0] ? p1[1]>p2[1] : p1[0]<p2[0];
        };
        int cnt = 0;
        sort(begin(points),end(points),lamda);
        int n = points.size();
        for(int i = 0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            int maxy = INT_MIN;
            for(int j = i+1;j<n;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y2>y1) continue;
                if(maxy<y2){
                    maxy = y2;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};