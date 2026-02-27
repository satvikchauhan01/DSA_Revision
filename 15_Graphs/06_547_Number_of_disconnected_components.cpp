#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void dfs(int city, vector<vector<int>>& arr, vector<bool> &visited){
        //mark the city as visited:
        visited[city]=true;

        //now go on and check for its neighbour
        for(int neighbourCity=0; neighbourCity<arr.size(); neighbourCity++){
            if(arr[city][neighbourCity] == 1   && !visited[neighbourCity]){
                dfs(neighbourCity, arr, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<bool> visited(n,false);

        //loop over all the cities
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout<<s.findCircleNum(isConnected)<<endl;
    return 0;
}