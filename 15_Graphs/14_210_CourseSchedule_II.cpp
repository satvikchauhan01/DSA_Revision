#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int node, vector<vector<int>> &adj, vector<int>&vis, vector<int> &path, vector<int> &result){
        path[node]=1;
        vis[ node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                
                if(dfs(it, adj, vis, path, result)){
                    return true;
                }
            }
            else if(path[it]==1){
                return true;
            }
        }
        path[node]=0;
        result.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        
        for(auto &it: prerequisites){
            int u=it[0];
            int v=it[1];

            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        vector<int>path(n,0);
        vector<int> result;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, path, result)){
                    return {};
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int N, P;
        cin >> N >> P;
        vector<vector<int>> prerequisites(P, vector<int>(2));
        for(int i = 0; i < P; i++) {
            cin >> prerequisites[i][0] >> prerequisites[i][1];
        }
        Solution ob;
        vector<int> ans = ob.findOrder(N, prerequisites);
        if(ans.size() == 0) {
            cout << "No\n";
        } else {
            for(int i: ans) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}