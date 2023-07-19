#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    bool isSafe(int x, int y, vector<string> &board, int n)
    {
        int temp = y-1;
        //same row
        while(temp >= 0)
        {
            if(board[x][temp] == 'Q') return false;
            temp--;
        }

        //upper diagonal
        temp = y-1;
        int tempx = x-1;
        while(temp >= 0 && tempx >= 0)
        {
            if(board[tempx][temp] == 'Q') return false;
            temp--;
            tempx--;
        }

        //lower diagonal
        temp = y-1;
        tempx = x+1;
        while(temp >=0 && tempx <n)
        {
            if(board[tempx][temp] == 'Q') return false;
            temp--;
            tempx++;
        }

        return true;
    }
    void solve(vector<vector<string>> &ans, vector<string> &board, int row, int col, int n)
    {
        if(col == n) return;
        for(int i = 0; i<n; i++)
        {
            if(isSafe(i, col, board, n))
            {
                board[i][col] = 'Q';
                if(col == (n-1))
                {
                    ans.push_back(board);
                }
                solve(ans, board, row, col+1, n);
                board[i][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s;
        for(int i = 0; i<n; i++)
        {
            s.push_back('.');
        }
        vector<string> board(n,s);
        int row = 0;
        solve(ans, board, row, 0, n);
        return ans;
    }
};

int main()
{

    return 0;
}