#include <bits/stdc++.h>
using namespace std;
#define ll long long

class dirgraph{
int n;
vector<vector<int>> adj;
public:

dirgraph(int a)
{
    n = a;
    vector<vector<int>> g(a);
    adj = g;
}

void addEdge(int a, int b)
{
    adj[a].push_back(b);
    //it means that there is a directed from a to b
}

void bfsrecur(int cur, )
void bfs(int source)
{
    vector<bool> visited(n,false);
    visited[source] = true;

    for(int i = 0; i<n; i++)
    {
        if(!visited[i])
        {
            bfsrecur(i,visited)
        }
    }
}

};


//main function
int main()
{

    return 0;
}