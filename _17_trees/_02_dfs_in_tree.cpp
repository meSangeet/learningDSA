#include<bits/stdc++.h>
using namespace std;

int depth[100000] = {0}, height[100000] = {0};

void dfs(int vertex, vector<vector<int>> &tree, int par = 0)
{
    for(auto child: tree[vertex])
    {
        if(child == par)
        {
            continue;
        }

        depth[child] = depth[vertex] + 1;
        dfs(child, tree, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main()
{
    cout<<"enter number of nodes in tree - ";

    int n; cin>>n;

    vector<vector<int>> tree(n+1);

    cout<<"enter the edges for your tree"<<endl;

    for(int i = 1; i<n; i++)
    {
        int a, b; cin>>a>>b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    //considering 1 is the top     taking 0 for overflow handling with depth -1
    depth[0] = -1;
    dfs(1, tree);

    cout<<endl<<"depths and heights of all the nodes - "<<endl;

    for(int i = 0; i<n; i++)
    {
        cout<<"node "<<i+1<<" - (height - "<<height[i+1]<<") (depth - "<<depth[i+1]<<")"<<endl;
    }
}