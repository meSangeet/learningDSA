#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[100000] = {false};
bool dfsvis[100000] = {false};
bool cycle = false; //flag to check whether there is a cycle or not

/*
To detect cycle in a directed graph using dfs we need to arrays one is visited and one is dfs visited

*/
void checkCycle(vector<vector<ll>> &graph, int x)
{
    vis[x] = true;
    dfsvis[x] = true;

    for(auto neighbour: graph[x])
    {
        if(!vis[neighbour])
        {
            checkCycle(graph, neighbour);
        }else{
            if(dfsvis[neighbour])
            {
                cycle = true;
                return;
            }
        }
    }

    dfsvis[x] = false;
    return;
}
int main()
{
    cout<<"enter number of vertex in the graph - ";
    ll n; cin>>n;
    vector<vector<ll>> graph(n);   
    ll e;
    cout<<"enter the number of edges - "; cin>>e;
    cout<<endl<<"enter the pair of vertices containing edges between them - "<<endl;
    for(int i = 0; i<e; i++)
    {
        ll a,b; cin>>a>>b;
        graph[a].push_back(b);
    }

    for(int i = 0; i<n; i++){
        if(!vis[i])
        checkCycle(graph, i);
    }

    if(cycle){
        cout<<endl<<"cycle exists"<<endl;
    }else{
        cout<<endl<<"cycle do not exists"<<endl;
    }
    return 0;
}