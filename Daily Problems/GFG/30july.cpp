class Solution {
  public:
    void function(int i, int j, vector<vector<int>> &mat, string &s, vector<string> &ans)
    {
        
        int n = mat.size();
        if(i == n-1 && j == n-1)
        {
            ans.push_back(s);
            return;
        }
        vector<int> a = {-1,0,1,0};
        vector<int> b = {0,1,0,-1};
        
        for(int p = 0; p<4; p++)
        {
            int nr = i+a[p];
            int nc = j+b[p];
            
            if(nr >= 0 && nr < n && nc >=0 && nc < n)
            {
                if(mat[nr][nc] == 1)
                {
                    if(p == 0){
                        s.push_back('U');
                    }
                    if(p == 1)
                    {
                        s.push_back('R');
                    }
                    if(p == 2)
                    {
                        s.push_back('D');
                    }
                    if(p == 3)
                    {
                        s.push_back('L');
                    }
                    
                    mat[nr][nc] = 2;
                    function(nr,nc,mat,s,ans);
                    mat[nr][nc] = 1;
                    s.pop_back();
                }
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> ans;
        int n = mat.size();
        string s = "";
        if(mat[0][0] != 1 || mat[n-1][n-1] != 1)
        {
            return ans;
        }
        mat[0][0] = 2;
        function(0,0, mat,s, ans);
        return ans;
    }
};