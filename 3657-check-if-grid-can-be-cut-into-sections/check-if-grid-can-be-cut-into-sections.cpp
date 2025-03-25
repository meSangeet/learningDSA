class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x,y;
        n = rectangles.size();
        for(int i = 0; i<n; i++){
            x.push_back({rectangles[i][0], rectangles[i][2]});
            y.push_back({rectangles[i][1], rectangles[i][3]});
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int lx = x[0][1];
        int ly = y[0][1];
        int c1 = 0, c2 = 0;
        for(int i = 1; i<n; i++){
            if(x[i][0] >= lx){
                c1++;
            }
            if(y[i][0] >= ly) c2++;
            lx = max(lx, x[i][1]);
            ly = max(ly, y[i][1]);
        }
        // cout<<c1<<endl<<c2<<endl;
        if(c1 > 1 or c2 > 1) return true;
        return false;
    }
};