#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool isSafe(int x, int y, vector<vector<int>> &board, int n)
    {
        int tempx = x, tempy = y;

        //same row
        tempy--;
        while(tempy >= 0)
        {
            if(board[x][tempy] == 1) return false;
            tempy--;
        }
        
        //upperdiagonal
        tempy = y-1;
        tempx = x-1;
        while(tempx >= 0 && tempy >= 0)
        {
            if(board[tempx][tempy] == 1) return false;
            tempx--;
            tempy--;
        }

        //lower diagonal

        tempy = y-1;
        tempx =  x+1;
        while(tempy >= 0 && tempx<n)
        {
            if(board[tempx][tempy] == 1) return false;
            tempy--;
            tempx++;
        }

        return true;
    }

    void solve(vector<vector<int>> &board, int &count, int col, int n)
    {
        if(col == n)  return;
        for(int i = 0; i<n; i++)
        {
            if(isSafe(i, col, board, n))
            {
                board[i][col] = 1;
                if(col == (n-1))
                {
                    count++;
                }
                solve(board, count, col+1, n);
                board[i][col] = 0;

            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<int>> board;
        for(int i = 0; i<n; i++)
        {
            vector<int> temp;
            for(int j = 0; j<n; j++)
            {   
                temp.push_back(0);
            }
            board.push_back(temp);
        }

        int col = 0;
        int count  = 0;

        solve(board, count, col, n);
        return count;
    }
};

int main()
{

    return 0;
}