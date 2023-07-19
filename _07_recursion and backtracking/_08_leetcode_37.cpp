#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool isSafe(vector<vector<char>>& board, char temp, int i, int j)
    {
        for(int a = 0; a<9; a++) 
            if(board[a][j] == temp || board[i][a] == temp) return false;
        int x = i/3, y = j/3;
        int rs = x*3, cs = y*3;

        for(int p = rs; p<rs+3; p++)
        {
            for(int q = cs; q<cs+3; q++)
            {
                if(temp == board[p][q]) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i = 0; i<9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                if(board[i][j] == '.'){
                    for(char k = '1'; k<='9'; k++)
                    {
                    if(isSafe(board, k, i, j))
                    {
                        board[i][j] = k;
                        if(solve(board)) return true;
                        else board[i][j] = '.';
                    }
                    }
            return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main()
{
     return 0;
}