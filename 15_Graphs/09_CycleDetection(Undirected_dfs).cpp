#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, unordered_map<int,int> &parent){
        visited[node]=true;
        
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                parent[neighbour]=node;
                if(dfs(neighbour, adj, visited, parent) == true){
                return true;
                }
            }
            else if(parent[node]!=neighbour) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &it: edges){
            int u=it[0];
            int v=it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                unordered_map<int,int> parent;
                if(dfs(i, adj, visited, parent)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    int V=5;
    vector<vector<int>> edges={{0,1},{1,2},{2,3},{3,4},{4,1}};
    cout<<s.isCycle(V, edges)<<endl;    
}