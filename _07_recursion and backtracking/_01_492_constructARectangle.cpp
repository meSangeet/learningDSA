#include <bits/stdc++.h>
using namespace std;

int positive(int a, int b){
    if(a>b) return a-b;

    return b-a;
}

vector<int> constructRectangle(int area) {
        int mindiff = INT_MAX;
        vector<int> ans = {-1,-1};
        for(int i = 1; i<area/2; i++)
        {
            int j = area/i;
            if(i*j == area)
            {
                int diff = positive(i,j);
                if(mindiff > diff)
                {
                    ans.pop_back();
                    ans.pop_back();
                    ans.push_back(i);
                    ans.push_back(j);
                    mindiff = diff;
                }
            }
        }
        return ans;
}


int main()
{
    int area; cin>>area;
    vector<int> ans;
    ans = constructRectangle(area);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}