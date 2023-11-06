#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
private:

    int rows;
    int cols;
    void dfs(int row, int col, vector<vector<char>> &board, int r[], int c[])
    {
        board[row][col] = 'a';
        for(int i = 0; i<4; i++)
        {
            int newRow = row + r[i],  newCol = col + c[i];
            if(newRow >= 0 && newRow < rows && newCol >=0 && newCol < cols)
            {
                if(board[newRow][newCol] == 'O')
                {
                    dfs(newRow, newCol, board, r, c);
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int r[] = {-1,0,1,0};
        int c[] = {0,-1,0,1};
        rows = board.size();
        cols = board[0].size();
        for(int i = 0; i<board.size(); i++)
        {
            if(board[i][0] == 'O')
            dfs(i,0,board,r,c);
        }
        for(int i = 0; i<board[0].size(); i++)
        {
            if(board[0][i] == 'O')
            dfs(0,i,board,r,c);
        }
        for(int i = 0; i<board.size(); i++)
        {
            if(board[i][cols-1] == 'O')
            dfs(i, board[0].size()-1, board,r,c);
        }
        for(int i = 0; i<board[0].size(); i++)
        {
            if(board[rows-1][i] == 'O')
            dfs(board.size()-1, i, board,r,c);
        }

        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                if(board[i][j] == 'O' || board[i][j] == 'X')
                {
                    board[i][j] = 'X';
                }else{
                    board[i][j] = 'O';
                }
            }
        }
    }
};

//main function
int main()
{

    return 0;
}