#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    1 - ongoing 
    2 - not a safe state
    3 -  a safe state
    */
    
    bool helper(int node, vector<vector<int>> &graph, vector<int> &visited){
        //we will mark the ongoing node as 1
        visited[node] = 1;
        // if(node == 4){
        //     cout<<"inside node 4"<<endl;
        // }
        bool isEventualSafeState = true;
        for(int neighbour : graph[node]){
            // cout<<"processing for neighbour
            // ghbour]<<endl;
            if(visited[neighbour] == -1){
                bool a = helper(neighbour, graph, visited);
                if(!a){
                    isEventualSafeState = false;
                }
            }else{
                if(visited[neighbour] == 2){
                    isEventualSafeState = false;
                }
                if(visited[neighbour] == 1){
                    isEventualSafeState = false;
                }
            }
        }
        // cout<<isEventualSafeState<<endl;
        if(isEventualSafeState){
            visited[node] = 3;
            return true;
        }
        
        visited[node] = 2;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        for(int i = 0; i<n; i++){
        if(visited[i] == -1){
            bool comp = helper(i, graph, visited);
        }
        }
        vector<int> ans;
        for(int node = 0; node < n; node++){
            cout<<node<<" "<<visited[node]<<endl;
            if(visited[node] == 3) ans.push_back(node);
        }
        
        return ans;
    }
};