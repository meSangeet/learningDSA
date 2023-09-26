#include<bits/stdc++.h>
using namespace std;
int height[100000] = {0};

void calHeight(vector<vector<int>> &tree, int vertex, int par = 0)
{
    for(int child: tree[vertex])
    {
        if(par == child) continue;
        calHeight(tree, child, vertex);
        height[vertex] = max(height[child]+1, height[vertex]);
    }
}

int main()
{
    int n; cin>>n;
    vector<vector<int>> tree(n+1);
    vector<int> top;
    for(int i = 1; i<=n; i++)
    {
        int p; cin>>p;
        if(p != -1)
        {
            tree[p].push_back(i);        
        }else{
            top.push_back(i);
        }
    }
    height[0] = -1;
    for(auto i:top){
    calHeight(tree,i);
    }
    int ans = 0;
    cout<<endl;
    for(auto i:top) ans = max(ans, height[i]);
    cout<<ans+1<<endl;
    return 0;
}