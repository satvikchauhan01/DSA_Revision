#include<bits/stdc++.h>
using namespace std;    
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int> q;
        int n=adj.size();
        vector<bool> isVisited(n,false);
        vector<int> result;
        q.push(0);
        isVisited[0] =true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            result.push_back(front);
            
            for(auto bagal: adj[front]){
                if(!isVisited[bagal]){
                    q.push(bagal);
                    isVisited[bagal]=true;
                }
            }
        }
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

        adj[u].push_back(v);            //we do this for both directed and undirected graph as in directed graph only one way possible
        adj[v].push_back(u);          //we do this only for undirected graph as both way possible
    }
    Solution obj;
    vector<int> bfsResult=obj.bfs(adj);
    cout<<"BFS Traversal: ";
    for(auto i: bfsResult){
        cout<<i<<" ";
    }
}