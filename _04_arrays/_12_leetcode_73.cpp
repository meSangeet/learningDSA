#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool r = false, c = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if(i == 0) r = true;
                    if(j == 0) c = true;
                }
            }
        }
        for(int i = 1; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if(c){
             for(int i = 0; i<m; i++) matrix[i][0] = 0;
        }
       
        if(r){
            for(int i = 0; i<n; i++) matrix[0][i] = 0;
        }
        
    }
};
int main()
{
    
    return 0;
}