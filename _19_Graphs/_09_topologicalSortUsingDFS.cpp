#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited, stack<int> &topo)
{
    visited[node] = true;
    for(int neighbour: graph[node])
    {
        if(!visited[neighbour])
        {
            dfs(graph, neighbour, visited, topo);
            topo.push(neighbour);
        }
    }
}

//main function
int main()
{
    int nodes;
    cout<<"enter number of nodes - "; cin>>nodes;

    int edges; cout<<"enter number of edges - "; cin>>edges;

    vector<vector<int>> graph(nodes);

    for(int i = 0; i<edges; i++)
    {
        int node1, node2;
        //edge -> (node1 -> node2)
        //graph should be directed acyclic

        cin>>node1>>node2;

        graph[node1].push_back(node2);
    }

    vector<bool> visited(nodes, false);
    stack<int> topo;
    for(int i = 0; i<nodes; i++)
    {
        if(!visited[i])
        {
            dfs(graph, i, visited, topo);
            topo.push(i);
        }
    }
    cout<<endl<<"topological sort looks like - "<<endl;
    while(!topo.empty())
    {
        cout<<topo.top()<<" ";
        topo.pop();
    }
    return 0;
}