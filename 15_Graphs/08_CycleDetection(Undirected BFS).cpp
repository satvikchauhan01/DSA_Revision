#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool bfs(int start, vector<vector<int>>& adj, vector<bool> &visited){
        queue<int> q;
        unordered_map<int, int> parent;
        
        //for first node
        visited[start]=true;
        q.push(start);
        parent[start]=-1;
        
        //now go on:
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(int neighbour: adj[node]){
                if(!visited[neighbour]){
                   visited[neighbour]=true;
                    q.push(neighbour);
                    parent[neighbour]=node; 
                }
                else if(parent[node] !=neighbour) return true;
                
            }
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
                if(bfs(i,adj, visited)){
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
    return 0;
}