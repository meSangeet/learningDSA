#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[100000] = {false};
vector<ll> ddfs;
ll cc = 1; //no of connected components
bool cycle = false; //flag to check whether there is a cycle or not
void dfs(vector<vector<ll>> &graph, ll source, ll prev)
{
    if(vis[source] == false){
        ddfs.push_back(source);
        vis[source] = true;
    }

    for(int i = 0; i<graph[source].size(); i++)
    {
        if(vis[graph[source][i]]){
            if(graph[source][i] != prev)
            {
                cycle = true;
            }
            continue;
        }

        dfs(graph, graph[source][i],  source);
    }
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
        graph[b].push_back(a);
    }

    cout<<"\nenter a vertex to start dfs from - "; ll x; cin>>x;
    dfs(graph, x, x);

    for(int i = 0; i<n; i++)
    {
        if(!vis[i])
        {
            cc++;
            dfs(graph, i, i);
        }
    }


    cout<<"\n DFS of the graph - ";

    for(int i = 0; i<ddfs.size(); i++)
    {
        cout<<ddfs[i]<<" ";
    }
    cout<<endl;

    cout<<"no of connected components - "<<cc<<endl;

    if(cycle)
    {
        cout<<"graph contains a cycle";
    }else{
        cout<<"graph do not contains a cycle";
    }
    return 0;
}