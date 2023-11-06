#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<int>> &graph, vector<int>& distances, vector<bool> &visited)
{

}

//main function
int main()
{
    cout<<"enter number of vertices - ";
    int n; cin>>n;
    cout<<"enter number of edges - ";
    int e; cin>>e;
    vector<vector<int>> graph(n);
    cout<<"enter source - ";
    int s; cin>>s;

    vector<int> distances(n,-1);
    distances[s] = 0;
    vector<bool> visted(n, false);

    
    return 0;
}