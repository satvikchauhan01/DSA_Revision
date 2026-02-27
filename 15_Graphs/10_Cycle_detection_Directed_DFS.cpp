#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &path){
        visited[node]=1;
        path[node]=1;
        
        for(auto next: adj[node]){
            if(!visited[next]){
                if(dfs(next, adj, visited, path) ==true){
                    return true;
                }
            }
            else if(path[next]==1){   //means that this next node is already been visited in this path so a cycle must be present
                return true;
                
            }
        }
        path[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &it : edges){
            int u=it[0];
            int v=it[1];
            
            adj[u].push_back(v);
        }
        vector<int> visited(V,0);
        vector<int> path(V,0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, path)){
                    return true;  //if bfs returns that it has cycle then return true 
                }
            }
        }
        return false;  //or at the end if all nodes tarversed then return false no loop;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges(E, vector<int>(2));
        for(int i = 0; i < E; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }
        Solution ob;
        if(ob.isCyclic(V, edges)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}