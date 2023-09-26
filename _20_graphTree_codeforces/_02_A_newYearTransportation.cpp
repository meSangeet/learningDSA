#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[100000] = {false};

void dfs(ll vertex, vector<vector<ll>>  &graph)
{
    vis[vertex] = true;
    for(ll neighbour:graph[vertex])
    {
        if(!vis[neighbour])
        {
            dfs(neighbour, graph);
        }
    }
}
void solve()
{
    ll n,t;
    cin>>n>>t;
    vector<vector<ll>> graph(n+1);
    for(int i = 1; i<=n-1; i++)
    {
        ll p; cin>>p;
        graph[i].push_back(i + p);
    }
    

    dfs(1, graph);

    if(vis[t]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}   

int main()
{
    solve();
    return 0;
}