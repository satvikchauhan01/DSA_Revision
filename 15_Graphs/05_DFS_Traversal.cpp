#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool> &visited, vector<int> &result){
        visited[node]=true;
        result.push_back(node);
        
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited, result);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> result;
        vector<bool> visited(adj.size(), false);
        
        dfs(0, adj, visited, result);
        return result;
    }
};
int main(){
    int n; //number of vertices
    int m; //number of edges
    cout<<"Enter the Number of Vertices: "; cin>>n;
    cout<<"Enter the Number of edges :   "; cin>>m;

    vector<vector<int>> adj(n);

    for(int i=0; i<m; i++){
        int u,v;
        cout<<"Enter Pair: (u,v): ";      //u and v are the vertices that are connected by an edge
        cin>>u>>v;

        adj[u].push_back(v);            
        adj[v].push_back(u);          
    }
    Solution obj;
    vector<int> dfsResult=obj.dfs(adj);
    cout<<"DFS Traversal: ";
    for(auto i: dfsResult){
        cout<<i<<" ";
    }
}