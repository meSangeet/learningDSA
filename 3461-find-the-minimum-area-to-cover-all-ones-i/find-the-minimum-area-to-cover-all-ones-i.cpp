class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size(); // row
        int n=grid[0].size();  // column

        int min_row=m;  // these values will be updated
        int max_row=-1;

        int min_col=n;
        int max_col=-1;

        for(int i=0;i<m;i++){   // iterate through the matrix
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){  // got the "1"

                    min_row=min(min_row,i);  // update the values
                    max_row=max(max_row,i);

                    min_col=min(min_col,j);
                    max_col=max(max_col,j);
                }
            }
        }

        return (max_row-min_row+1)*(max_col-min_col+1);   // area (+1) as it is 0 indexed
        
    }
};