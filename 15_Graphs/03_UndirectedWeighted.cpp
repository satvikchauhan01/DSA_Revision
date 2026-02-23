#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; //number of vertices
    int m; //number of edges
    cout<<"Enter the Number of Vertices: "; cin>>n;
    cout<<"Enter the Number of edges :   "; cin>>m;

    unordered_map<int, list<pair<int, int>>> adjList;

    for(int i=0; i<m; i++){
        int u,v,w;
        cout<<"Enter Pair: (u,v,w) where w is the weight";      
        cin>>u>>v>>w;

        adjList[u].push_back({v,w});            
        adjList[v].push_back({u,w});          
    }
    cout<<"Adjacecny List: "<<endl;
    for(auto i: adjList){
        cout<<i.first<<": ";
        for(auto j: i.second){
            cout<<"("<<j.first<<","<<j.second<<")";
        }
        cout<<endl;
    }
}