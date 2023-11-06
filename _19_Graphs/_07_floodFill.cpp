#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int check = image[sr][sc];
        if(check == color)
        {
            return image;
        }
        queue<pair<int,int>> q; // queue for bfs
        int r[] = {-1,0,1,0}, c[] = {0,-1,0,1}; //arrays to traverse different coordinates

        int rows = image.size(), cols = image[0].size();

        q.push({sr,sc});

        while(!q.empty())
        {
            auto coordinate = q.front();
            q.pop();
            int R = coordinate.first, C = coordinate.second;
            image[R][C] = color;

            for(int i = 0; i<4; i++)
            {
                int newRow = R + r[i];
                int newCol = C + c[i];
                if(newRow >= 0 && newRow < rows && newCol >=0 && newCol < cols){
                if(image[newRow][newCol] == check)
                {
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
                }
            }
        } 
        return image;
    }
};

//main function
int main()
{

    return 0;
}