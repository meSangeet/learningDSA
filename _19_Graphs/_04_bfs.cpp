#include <bits/stdc++.h>
using namespace std;
#define ll long long



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

    vector<int> distances(n,0);
    distances[s] = 0;

    
    return 0;
}