class Solution {
public:
    int solve(int row,int col,vector<vector<int>>&v,vector<vector<int>>&dp)
    {
        if(col==v[0].size()-1)
            return 0;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int x=0,y=0,z=0;
        
        if(row-1>=0 && col+1<v[0].size() && v[row-1][col+1]>v[row][col])
            x=1+solve(row-1,col+1,v,dp);

        if(col+1<v[0].size() && v[row][col+1]>v[row][col])
            y=1+solve(row,col+1,v,dp);

        if(row+1<v.size() && col+1<v[0].size() && v[row+1][col+1]>v[row][col])
            z=1+solve(row+1,col+1,v,dp);

        dp[row][col] = max(x,max(y,z));
        return dp[row][col];
    }

    int maxMoves(vector<vector<int>>& v) {
        int ans=0;
        vector<vector<int>>dp(v.size(),vector<int>(v[0].size(),-1));
        for(int i=0;i<v.size();i++)
            ans=max(ans,solve(i,0,v,dp));
        return ans;
    }
};