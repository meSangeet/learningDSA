#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<bool> &pathVisited, vector<bool> &status)
{
    visited[node] = true;
    pathVisited[node] = true;
    bool safe = true;
    for(int neighbour: graph[node])
    {
        if(!visited[neighbour] && !pathVisited[neighbour])
        {
            dfs(graph, neighbour, visited, pathVisited, status);
            safe = status[neighbour];
            if(safe == false)
            {
                break;
            }
        }else if(pathVisited[neighbour]){
            status[neighbour] = false;
            safe = false;
            break;
        }else{
            if(visited[neighbour])
            {
                safe = status[neighbour];
                if(safe == false)
                {
                    break;
                }
            }
        }
    }
    status[node] = safe;
    pathVisited[node] = false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int nodes = graph.size();
    vector<bool> visited(nodes, false);
    vector<bool> pathVisited(nodes, false);
    vector<bool> status(nodes, false);

    for(int i = 0; i<nodes; i++)
    {
        if(!visited[i])
        {
            dfs(graph, i, visited, pathVisited, status);
        }
    }
    //after the dfs for all the nodes we will get the updates status array

    vector<int> ans;
    for(int i = 0; i<nodes; i++)
    {
        if(status[i])
        {
            ans.push_back(i);
        }
    }

    return ans;
}
};

//main function
int main()
{

    return 0;
}