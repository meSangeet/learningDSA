#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int total = row*col;

        int rowStart = 0, colStart = 0;
        int rowEnd = row-1;
        int colEnd = col-1;

        int count = 0;
        vector<int> ans;
        while(count < total)
        {
            for(int i = colStart; i<=colEnd; i++)
            {
                if(count < total)
                ans.push_back(matrix[rowStart][i]);
                count++;
            }
            rowStart++;

            for(int i = rowStart; i<=rowEnd; i++)
            {
                if(count < total)
                ans.push_back(matrix[i][colEnd]);
                count++;
            }
            colEnd--;

            for(int i = colEnd; i>=colStart; i--)
            {
                if(count < total)
                ans.push_back(matrix[rowEnd][i]);
                count++;
            }
            rowEnd--;

            for(int i = rowEnd; i>=rowStart; i--)
            {
                if(count < total)
                ans.push_back(matrix[i][colStart]);
                count++;
            }
            colStart++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}