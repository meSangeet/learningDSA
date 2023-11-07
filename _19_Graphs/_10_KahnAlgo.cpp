#include <bits/stdc++.h>
using namespace std;
#define ll long long

//main function
int main()
{   
    //variables
    int nodes; 
    int edges;
    cout<<"enter the number of nodes - ";
    cin>>nodes;
    cout<<"enter the number of edges - ";
    cin>>edges;

    vector<vector<int>> graph(nodes);
    vector<int> indegree(nodes, 0);
    for(int i = 0; i<edges; i++)
    {
        int node1, node2;

        //edge = (node1 -> node2)

        cin>>node1>>node2;
        graph[node1].push_back(node2);

        indegree[node2]++;
    }

    queue<int> q; //used for bfs

    for(int i = 0; i<nodes; i++)
    {
        if(!indegree[i])
        {
            q.push(i);
        }
    }


    //bfs implementation

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int neighbour: graph[node])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }

    }
    return 0;
}